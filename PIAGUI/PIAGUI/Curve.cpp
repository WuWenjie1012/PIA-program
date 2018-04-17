#include "Curve.h"
using namespace std;

Curve::Curve()
{
	DataNum = 0;	// DataNum+1 is the number of data points(P0...Pn)
	Degree = 0;	// The degree of basis functions.
	CtlNum = 0;	// CtlNum+1 is the number of contrl points
	PosNum = 0;	// PosNum+1 is the number of points on curve
	Max = -INT_MAX;
	Min = INT_MAX;
	Mid = 0;
}

void Curve::loadDataFromFile(QString FileName)
{
	SetDegree(3);	// Cubic Bspline curve
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
			stream1 >> temp.x >> temp.y;
			temp.z = 0;

			Max = Max < temp.x ? temp.x : Max;
			Max = Max < temp.y ? temp.y : Max;
			Max = Max < temp.z ? temp.z : Max;

			Min = Min > temp.x ? temp.x : Min;
			Min = Min > temp.y ? temp.y : Min;
			Min = Min > temp.z ? temp.z : Min;

			DataPoints.push_back(temp);
		}

		if (wordArray.size() == 3)
		{
			stream1 >> temp.x >> temp.y >> temp.z;

			Max = Max < temp.x ? temp.x : Max;
			Max = Max < temp.y ? temp.y : Max;
			Max = Max < temp.z ? temp.z : Max;

			Min = Min > temp.x ? temp.x : Min;
			Min = Min > temp.y ? temp.y : Min;
			Min = Min > temp.z ? temp.z : Min;

			DataPoints.push_back(temp);
		}
	}
	fin.close();

	Mid = (Max + Min) / 2;
	Normalize();

	CalculateDataParameter();
	cout << "The data num: " << DataPoints.size() << endl;
	cout << "The data para num: " << GetDataParameter().size() << endl;

	int pc;
	cout << "Please put in the number of contrl points: ";
	cin >> pc;
	CtlNum = pc - 1;
	CalculateCtlSequence();
	CalculateCtlPoints();
	CalculateKnotVector();

	cout << "The number of control points is: ";
	cout << CtlPoints.size() << endl;
	cout << "Please put in the number of points on curve: ";
	cin >> pc;
	PosNum = pc;
	CalculateCurvePoints();
	cout << "The number of points on curve is: ";
	cout << PointsOnCurve.size() << endl;

	CalculateDifferenceVector();
	CalculatePresentError();
}

void Curve::Normalize()
{
	for (int i = 0; i < DataPoints.size(); i++)
	{
		DataPoints[i].x = (DataPoints[i].x - Mid) * 2.0 / (Max - Min);
		DataPoints[i].y = (DataPoints[i].y - Mid) * 2.0 / (Max - Min);
		DataPoints[i].z = (DataPoints[i].z - Mid) * 2.0 / (Max - Min);
	}
}

void Curve::CalculateCurvePoints()
{
	Cpoint pt;
	double u = 0;
	for (int i = 0; i < PosNum + 1; i++)
	{
		u = (double)i / PosNum;
		pt = CalculateOnePoint(u);
		PointsOnCurve.push_back(pt);
	}

}
Cpoint Curve::CalculateOnePoint(double u)
{
	int span = FindSpan(CtlNum, Degree, u, KnotVector);
	double *N = BasisFuns(span, u, Degree, KnotVector);
	Cpoint C;
	C.x = 0;
	C.y = 0;
	C.z = 0;
	for (int i = 0; i <= Degree; i++)
	{
		C.x = C.x + N[i] * CtlPoints[span - Degree + i].x;
		C.y = C.y + N[i] * CtlPoints[span - Degree + i].y;
		C.z = C.z + N[i] * CtlPoints[span - Degree + i].z;
	}
	return C;
}

void Curve::CalculateDataParameter()
{
	if (DataPoints.size() == 0)
		throw"The number of data points is 0! ";

	Vector3d pv(0, 0, 0);
	double sum = 0;
	double px, py, pz;
	DataParameters.push_back(0);
	for (int i = 0; i < DataPoints.size() - 1; i++)
	{
		px = DataPoints[i + 1].x - DataPoints[i].x;
		py = DataPoints[i + 1].y - DataPoints[i].y;
		pz = DataPoints[i + 1].z - DataPoints[i].z;
		Vector3d pv(px, py, pz);
		sum += pv.norm();
		DataParameters.push_back(sum);
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
	double pt, alph;
	int pk;
	double d = (DataNum + 1) / (CtlNum - 2);

	// For cubic B-spline curve, the knot vector is:
	// [0, 0, 0, 0, t4, t5, ... , tn, 1, 1, 1, 1]
	for (int i = 0; i < Degree + 1; i++)
		KnotVector.push_back(0);

	for (int i = 1; i < CtlNum - 2; i++)
	{
		pk = floor(i * d);
		alph = i * d - pk;
		pt = (1 - alph) * DataParameters[pk - 1] + alph * DataParameters[pk];
		KnotVector.push_back(pt);
	}

	for (int i = 0; i < Degree + 1; i++)
		KnotVector.push_back(1);

	//	for (int i = 0; i < KnotVector.size(); i++)
	//		cout << KnotVector[i] << endl;

	//	cout << KnotVector.size() << endl;
}

void Curve::CalculateDifferenceVector()
{
	Cpoint pt;
	double u;
	for (int i = 0; i < DataPoints.size(); i++)
	{
		u = DataParameters[i];
		pt = DataPoints[i] - CalculateOnePoint(u);
		DifferenceVector.push_back(pt);
	}
}

void Curve::CalculatePresentError()
{
	double pt;
	double max = 0;
	for (int i = 0; i < DifferenceVector.size(); i++)
	{
		pt = DifferenceVector[i].x * DifferenceVector[i].x + DifferenceVector[i].y * DifferenceVector[i].y + DifferenceVector[i].z * DifferenceVector[i].z;
		pt = sqrt(pt);
		max = pt > max ? pt : max;
	}

	PresentError = max;
}
