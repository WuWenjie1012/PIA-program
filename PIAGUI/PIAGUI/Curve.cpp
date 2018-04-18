#include "Curve.h"
using namespace std;

Curve::Curve()
{
	DataNum = 0;	// DataNum+1 is the number of data points(P0...Pn)
	Degree = 3;	// The degree of basis functions.
	CtlNum = 0;	// CtlNum+1 is the number of contrl points
	PosNum = 0;	// PosNum+1 is the number of points on curve
	Max = -INT_MAX;
	Min = INT_MAX;
	Mid = 0;
}

void Curve::loadDataFromFile(QString FileName)
{
	Degree = 3;	// Cubic Bspline curve
	vector<string>wordArray;
	string filename = FileName.toLocal8Bit().toStdString();
	ifstream fin(filename);
	string line, word;
	int col;
	Cpoint temp(0, 0, 0);
	while (getline(fin, line))
	{
		if (line.empty())
			continue;
		if (line[0] == '#')
			continue;
		istringstream stream(line);
		wordArray.clear();
		while (stream >> word)
		{
			wordArray.push_back(word);
		}
		istringstream stream1(line);

		if (wordArray.size() == 1)
		{
			stream1 >> col;
			SetPoiNum(col - 1);
		}

		if (wordArray.size() == 2)
		{
			stream1 >> temp.x() >> temp.y();
			temp.z() = 0;

			Max = Max < temp.x() ? temp.x() : Max;
			Max = Max < temp.y() ? temp.y() : Max;
			Max = Max < temp.z() ? temp.z() : Max;

			Min = Min > temp.x() ? temp.x() : Min;
			Min = Min > temp.y() ? temp.y() : Min;
			Min = Min > temp.z() ? temp.z() : Min;

			DataPoints.push_back(temp);
		}

		if (wordArray.size() == 3)
		{
			stream1 >> temp.x() >> temp.y() >> temp.z();

			Max = Max < temp.x() ? temp.x() : Max;
			Max = Max < temp.y() ? temp.y() : Max;
			Max = Max < temp.z() ? temp.z() : Max;

			Min = Min > temp.x() ? temp.x() : Min;
			Min = Min > temp.y() ? temp.y() : Min;
			Min = Min > temp.z() ? temp.z() : Min;

			DataPoints.push_back(temp);
		}
	}
	fin.close();

	Mid = (Max + Min) / 2;
	Normalize();

	DataNum = DataPoints.size() - 1;
	CalculateDataParameter();
	CalculateKnotVector();
	
	/*int pc;
	cout << "Please put in the number of points on curve: ";
	cin >> pc;
	PosNum = pc;
*/
	CalculateCurvePoints();
	cout << "The number of points on curve is: ";
	cout << PointsOnCurve.size() << endl;

	
	CalculateDataPointsOnCurve();
	CalculateDifferenceVector();
	CalculatePresentError();
}

void Curve::Normalize()
{
	for (int i = 0; i < DataPoints.size(); i++)
	{
		DataPoints[i].x() = (DataPoints[i].x() - Mid) * 2.0 / (Max - Min);
		DataPoints[i].y() = (DataPoints[i].y() - Mid) * 2.0 / (Max - Min);
		DataPoints[i].z() = (DataPoints[i].z() - Mid) * 2.0 / (Max - Min);
	}
}

void Curve::CalculateCurvePoints()
{
	
	double u = 0;
	PointsOnCurve.resize(PosNum + 1);
	for (int i = 0; i < PosNum + 1; i++)
	{
		u = (double)i / PosNum;
		PointsOnCurve[i] = CalculateOnePoint(u);
	}
}

void Curve::CalculateDataPointsOnCurve()
{
	DataPointsOnCurve.resize(DataNum + 1);
	for (int i = 0; i < DataPoints.size(); i++)
	{
		DataPointsOnCurve[i] = CalculateOnePoint(DataParameters[i]);
	}
}

Cpoint Curve::CalculateOnePoint(double u)
{
	int span = FindSpan(CtlNum, Degree, u, KnotVector);
	double *N = BasisFuns(span, u, Degree, KnotVector);
	Cpoint C(0, 0, 0);
	
	for (int i = 0; i <= Degree; i++)
	{
		C.x() = C.x() + N[i] * CtlPoints[span - Degree + i].x();
		C.y() = C.y() + N[i] * CtlPoints[span - Degree + i].y();
		C.z() = C.z() + N[i] * CtlPoints[span - Degree + i].z();
	}
	return C;
}

void Curve::CalculateDataParameter()
{
	if (DataPoints.size() == 0)
		throw"The number of data points is 0! ";

	Eigen::Vector3d pv(0, 0, 0);
	double sum = 0;
	double px, py, pz;
	DataParameters.resize(DataNum + 1);
	DataParameters[0] = 0;
	for (int i = 0; i < DataPoints.size() - 1; i++)
	{
		pv = DataPoints[i + 1] - DataPoints[i];

		sum += pv.norm();
		DataParameters[i+1] = sum;
	}

	for (int i = 0; i < DataParameters.size(); i++)
	{
		DataParameters[i] /= sum;
	}


}

void Curve::CalculateCtlSequence()
{
	int f;
	CtlSequence.push_back(0);
	for (int i = 1; i < CtlNum; i++)
	{
		f = (DataNum + 1)*i / CtlNum;
		CtlSequence.push_back(f);
		//	cout << f << endl;
	}
	CtlSequence.push_back(DataNum);
}

void Curve::CalculateCtlPoints()
{
	for (int i = 0; i < CtlNum + 1; i++)
	{
		CtlPoints.push_back(DataPoints[CtlSequence[i]]);
	}
}

void Curve::CalculateKnotVector()
{
	if (Method == 0)	// PIA method
	{
		CtlNum = DataNum;
		CtlPoints = DataPoints;
		KnotVector.resize(DataNum + Degree + 2);
		for (int i = 0; i < Degree + 1; i++)
			KnotVector[i] = 0;
		for (int i = Degree + 1; i < DataNum + 1; i++)
			KnotVector[i] = DataParameters[i - Degree + 1];
		for (int i = DataNum + 1; i < DataNum + 5; i++)
			KnotVector[i] = 1;
	}
	//double pt, alph;
	//int pk;
	//double d = (DataNum + 1) / (CtlNum - 2);

	//// For cubic B-spline curve, the knot vector is:
	//// [0, 0, 0, 0, t4, t5, ... , tn, 1, 1, 1, 1]
	//for (int i = 0; i < Degree + 1; i++)
	//	KnotVector[i] = 0;

	//for (int i = 1; i < CtlNum - 2; i++)
	//{
	//	pk = floor(i * d);
	//	alph = i * d - pk;
	//	pt = (1 - alph) * DataParameters[pk - 1] + alph * DataParameters[pk];
	//	KnotVector[i + Degree] = pt;
	//}

	//for (int i = 0; i < Degree + 1; i++)
	//	KnotVector[CtlNum + i + 1] = 1;

	//
}

void Curve::CalculateDifferenceVector()
{
	DifferenceVector.resize(DataNum + 1);
	for (int i = 0; i < DataPoints.size(); i++)
	{
		DifferenceVector[i] = DataPoints[i] - DataPointsOnCurve[i];
	}
}

void Curve::CalculatePresentError()
{
	double pt;
	double max = 0;
	for (int i = 0; i < DifferenceVector.size(); i++)
	{
		pt = DifferenceVector[i].norm();
		max = pt > max ? pt : max;
	}
	PresentError = max;
}

void Curve::OnePIAIterateStep()
{
	for (int i = 0; i < CtlPoints.size(); i++)
	{
		CtlPoints[i] = CtlPoints[i] + DifferenceVector[i];
	}

	CalculateDataPointsOnCurve();
	CalculateDifferenceVector();
	CalculatePresentError();
	CalculateCurvePoints();
}
