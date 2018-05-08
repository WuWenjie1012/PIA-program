#include "Curve.h"
using namespace std;

Curve::Curve()
{
	DataNum = -1;	// DataNum+1 is the number of data points(P0...Pn)
	Degree = 3;	// The degree of basis functions.
	CtlNum = -1;	// CtlNum+1 is the number of contrl points
	PosNum = -1;	// PosNum+1 is the number of points on curve
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

	DataNum = DataPoints.size() - 1;

	Mid = (Max + Min) / 2;
	Normalize();

	DataPns = Eigen::MatrixXd::Zero(DataNum + 1, 3);
	for (int i = 0; i <= DataNum; i++)
		DataPns.row(i) = DataPoints[i];
		

	
}

void Curve::Init()
{
	CalculateDataParameter();
	CalculateKnotVector();

	CalculateConfigurationMatrixA();

	if (IteType == 1)
	{
		miu = Eigen::MatrixXd::Zero(CtlNum + 1, CtlNum + 1);
		for (int i = 0; i <= CtlNum; i++)
		{
			miu(i, i) = 1 / A.transpose().row(i).sum();
		}
	}

	CaclculateParametersOnCurve();
	CalculateCurvePoints();

	//CalculateDataPointsOnCurve();

	CalculateDifferenceVector();
	CalculatePresentError();

	QCtlPoints = CalculateQCtlPoints(CtlPns, KnotVector, Degree);
	RCtlPoints = CalculateRCtlPoints(QCtlPoints, KnotVector, Degree - 1);

	CalculateFirstDerivativeOnCurve();
	CalculateSecondDerivativeOnCurve();
	CalculateCurvatureOnCurve();

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


void Curve::CaclculateParametersOnCurve()
{
	ParametersOnCurve.resize(PosNum + 1);
	double u = 0;
	for (int i = 0; i < PosNum + 1; i++)
	{
		u = (double)i / PosNum;
		ParametersOnCurve[i] = u;
	}
}
void Curve::CalculateCurvePoints()
{
	
	PointsOnCurve.resize(PosNum + 1);
	for (int i = 0; i < PosNum + 1; i++)
	{
		PointsOnCurve[i] = CalculateOnePoint(ParametersOnCurve[i]);
	}
}


Cpoint Curve::CalculateOnePoint(double u)
{
	int span = FindSpan(CtlNum, Degree, u, KnotVector);
	double *N = BasisFuns(span, u, Degree, KnotVector);
	Cpoint C(0, 0, 0);
	Cpoint pt(0, 0, 0);

	for (int i = 0; i <= Degree; i++)
	{
		pt = N[i] * CtlPns.row(span - Degree + i);
		C = C + pt;
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
	CtlPns = Eigen::MatrixXd::Zero(CtlNum + 1, 3);
	for (int i = 0; i < CtlNum + 1; i++)
	{
		CtlPns.row(i) = DataPoints[CtlSequence[i]];
//		CtlPoints.push_back(DataPoints[CtlSequence[i]]);
	}
}

void Curve::CalculateKnotVector()
{
	if (IteType == 0)	// PIA method
	{
		CtlNum = DataNum;
		CtlPns = DataPns;
//		CtlPoints = DataPoints;
		KnotVector.resize(CtlNum + Degree + 2);
		for (int i = 0; i < Degree + 1; i++)
			KnotVector[i] = 0;
		for (int i = Degree + 1; i < DataNum + 1; i++)
			KnotVector[i] = DataParameters[i - Degree + 1];
		for (int i = DataNum + 1; i < DataNum + 5; i++)
			KnotVector[i] = 1;
	}
	else if (IteType == 1)	// LSPIA method
	{
		KnotVector.resize(CtlNum + Degree + 2);
		CalculateCtlSequence();
		CalculateCtlPoints();

		double pt, alph;
		int pk;
		double d = (DataNum + 1) / (CtlNum - 2);

		// For cubic B-spline curve, the knot vector is:
		// [0, 0, 0, 0, t4, t5, ... , tn, 1, 1, 1, 1]
		for (int i = 0; i < Degree + 1; i++)
			KnotVector[i] = 0;

		for (int i = 1; i < CtlNum - 2; i++)
		{
			pk = floor(i * d);
			alph = i * d - pk;
			pt = (1 - alph) * DataParameters[pk - 1] + alph * DataParameters[pk];
			KnotVector[i + Degree] = pt;
		}

		for (int i = 0; i < Degree + 1; i++)
			KnotVector[CtlNum + i + 1] = 1;
	}	
}

void Curve::CalculateDifferenceVector()
{
	Diff = Eigen::MatrixXd::Zero(DataNum + 1, 3);
	Diff = DataPns - A * CtlPns;
}

void Curve::CalculatePresentError()
{
	double pt;
	double max = 0;
	for (int i = 0; i <= DataNum; i++)
	{
		pt = Diff.row(i).norm();
		//pt = DifferenceVector[i].norm();
		max = pt > max ? pt : max;
	}
	PresentError = max;
}

Eigen::Vector3d Curve::CalculateOneFirstDerivative(double u, Eigen::MatrixXd qctlpoints, vector<double> knotvector, int degree)
{
	vector<double> ptU;
	ptU.resize(knotvector.size() - 2);
	for (int i = 0; i < ptU.size(); i++)
	{
		ptU[i] = knotvector[i + 1];
	}
	
	int pDegree = degree - 1;
	int pCtlNum = qctlpoints.rows() - 1;
	int span = FindSpan(pCtlNum, pDegree, u, ptU);
	double *N = BasisFuns(span, u, pDegree, ptU);
	
	Eigen::Vector3d pt(0, 0, 0);
	Eigen::Vector3d ppt(0 ,0, 0);
	for (int i = 0; i <= pDegree; i++)
	{	
		ppt = N[i] * qctlpoints.row(span - pDegree + i);
		pt = pt + ppt;
		//pt = pt + N[i] * qctlpoints.row(span - pDegree + i);
	}

	return pt;
}

Eigen::Vector3d Curve::CalculateOneSecondDerivative(double u, Eigen::MatrixXd rctlpoints, vector<double> knotvector, int degree)
{
	vector<double> ptU;
	ptU.resize(knotvector.size() - 4);
	for (int i = 0; i < ptU.size(); i++)
	{
		ptU[i] = knotvector[i + 2];
	}

	int pDegree = degree - 2;
	int pCtlNum = rctlpoints.rows() - 1;
	int span = FindSpan(pCtlNum, pDegree, u, ptU);
	double *N = BasisFuns(span, u, pDegree, ptU);

	Eigen::Vector3d pt(0, 0, 0);
	Eigen::Vector3d ppt(0, 0, 0);

	for (int i = 0; i <= pDegree; i++)
	{
		ppt = N[i] * rctlpoints.row(span - pDegree + i);
		pt = pt + ppt;
	}

	return pt;
}

Eigen::MatrixXd Curve::CalculateQCtlPoints(Eigen::MatrixXd ctlpns, vector<double> knotvector, int degree)
{
	int ctlnum = ctlpns.rows();
	Eigen::MatrixXd pt;
	pt.resize(ctlnum - 1, 3);

	for (int i = 0; i < ctlnum - 1; i++)
	{
	//	QCtlPoints[i] = (CtlPoints[i + 1] - CtlPoints[i]) * Degree / (KnotVector[i + Degree + 1] - KnotVector[i + 1]);
		pt.row(i) = (ctlpns.row(i + 1) - ctlpns.row(i)) * degree / (knotvector[i + degree + 1] - knotvector[i + 1]);

	}
	return pt;
}

Eigen::MatrixXd Curve::CalculateRCtlPoints(Eigen::MatrixXd ctlpns, vector<double> knotvector, int degree)
{
	int ctlnum = ctlpns.rows();
	Eigen::MatrixXd pt;
	pt.resize(ctlnum - 1, 3);

	for (int i = 0; i < ctlnum - 1; i++)
	{
		pt.row(i) = (ctlpns.row(i + 1) - ctlpns.row(i)) * degree / (knotvector[i + degree + 2] - knotvector[i + 2]);
	}

	return pt;
}

void Curve::CalculateFirstDerivativeOnCurve()
{
	FirstDerivativeOnCurve.resize(PosNum + 1);
	for (int i = 0; i < PosNum + 1; i++)
	{
		FirstDerivativeOnCurve[i] = CalculateOneFirstDerivative(ParametersOnCurve[i], QCtlPoints, KnotVector, Degree);
	}
}

void Curve::CalculateSecondDerivativeOnCurve()
{
	SecondDerivativeOnCurve.resize(PosNum + 1);
	for (int i = 0; i < PosNum + 1; i++)
	{
		SecondDerivativeOnCurve[i] = CalculateOneSecondDerivative(ParametersOnCurve[i], RCtlPoints, KnotVector, Degree);
	}
}

void Curve::CalculateCurvatureOnCurve()
{
	// Plane curve
	CurvatureOnCurve.resize(PosNum + 1);
	for (int i = 0; i < PosNum + 1; i++)
	{
		CurvatureOnCurve[i] = FirstDerivativeOnCurve[i].cross(SecondDerivativeOnCurve[i]).z() / pow(FirstDerivativeOnCurve[i].norm(), 3);
	}
}

void Curve::CalculateConfigurationMatrixA()
{
	A = Eigen::MatrixXd::Zero(DataNum + 1, CtlNum + 1);
	int span;
	double *N;
	for (int i = 0; i <= DataNum; i++)
	{
		span = FindSpan(CtlNum, Degree, DataParameters[i], KnotVector);
		N = BasisFuns(span, DataParameters[i], Degree, KnotVector);
		for (int j = span - Degree; j <= span; j++)
			A(i, j) = N[j - span + Degree];
	}
}

void Curve::OneIterateStep()
{
	switch (IteType)
	{
	case 0:
		CtlPns = CtlPns + Diff;
		break;
	case 1:
		CtlPns = CtlPns + miu * A.transpose() * Diff;
		break;
	default:
		break;
	}
	CalculateDifferenceVector();
	CalculatePresentError();
	
	CalculateCurvePoints();


	QCtlPoints = CalculateQCtlPoints(CtlPns, KnotVector, Degree);
	RCtlPoints = CalculateRCtlPoints(QCtlPoints, KnotVector, Degree - 1);

	CalculateFirstDerivativeOnCurve();
	CalculateSecondDerivativeOnCurve();
	CalculateCurvatureOnCurve();
}

void Curve::CalculateMatrixD1()
{
	Eigen::MatrixXd A_dsp = Eigen::MatrixXd::Zero(DataNum + 1, CtlNum + 1);
	for (int i = 0; i <= CtlNum; i++)
	{
		Eigen::MatrixXd pctlpns = Eigen::MatrixXd::Zero(CtlNum + 1, 3);
		pctlpns.row(i) = Eigen::MatrixXd::Ones(1, 3);
		Eigen::MatrixXd pQctlpns = CalculateQCtlPoints(pctlpns, KnotVector, Degree);
		for (int j = 0; j <= DataNum; j++)
		{
			A_dsp(j, i) = CalculateOneFirstDerivative(DataParameters[j], pQctlpns, KnotVector, Degree).x();
		}
		cout << "D1 Calculation " << (double)i * 100 / CtlNum << " %" << endl;

	}

	D1 = Eigen::MatrixXd::Zero(DataNum * 3 + 3, CtlNum * 3 + 3);
	D1.block(0, 0, DataNum + 1 , CtlNum + 1 ) = A_dsp;
	D1.block(DataNum + 1, CtlNum + 1, DataNum + 1, CtlNum + 1) = A_dsp;
	D1.block(DataNum * 2 + 2, CtlNum * 2 + 2, DataNum + 1, CtlNum + 1) = A_dsp;

	cout << "D1 Calculation Done!" << endl;
}

void Curve::CalculateMatrixD2()
{
	Eigen::MatrixXd A_ddsp = Eigen::MatrixXd::Zero(DataNum + 1, CtlNum + 1);
	for (int i = 0; i <= CtlNum; i++)
	{
		Eigen::MatrixXd pctlpns = Eigen::MatrixXd::Zero(CtlNum + 1, 3);
		pctlpns.row(i) = Eigen::MatrixXd::Ones(1, 3);

		Eigen::MatrixXd pQctlpns = CalculateQCtlPoints(pctlpns, KnotVector, Degree);
		Eigen::MatrixXd pRctlpns = CalculateRCtlPoints(pQctlpns, KnotVector, Degree - 1);

		for (int j = 0; j <= DataNum; j++)
		{
			A_ddsp(j, i) = CalculateOneSecondDerivative(DataParameters[j], pRctlpns, KnotVector, Degree).x();
		}

		cout << "D2 Calculation " << (double)i * 100 / CtlNum << " %" << endl;

	}

	D2 = Eigen::MatrixXd::Zero(DataNum * 3 + 3, CtlNum * 3 + 3);
	D2.block(0, 0, DataNum + 1, CtlNum + 1) = A_ddsp;
	D2.block(DataNum + 1, CtlNum + 1, DataNum + 1, CtlNum + 1) = A_ddsp;
	D2.block(DataNum * 2 + 2, CtlNum * 2 + 2, DataNum + 1, CtlNum + 1) = A_ddsp;

	cout << "D2 Calculation Done!" << endl;
}

void Curve::CalculateMatrixMc()
{

}