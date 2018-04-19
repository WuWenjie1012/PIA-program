#pragma once
#include "Bspline.h"
#include <Eigen\Core>
#include <QtWidgets/QMainWindow>
//using namespace Eigen;
//typedef Eigen::Vector3d cpoint;

class Curve :public Bspline
{
public:
	Curve();
	//Curve(QString filename);
	~Curve() {};
	
	//Cpoint CalculateOnePoint(double u)  override;	//Calculate one point on the curve
	//void renderScene() override;
	vector<double> GetKnotVector() { return KnotVector; }
	vector<double> GetDataParameter() { return DataParameters; }

	vector<Cpoint> GetCtlPoints() { return CtlPoints; }
	vector<Cpoint> GetDataPoints() { return DataPoints; }
	vector<Cpoint> GetCurvePoints() { return PointsOnCurve; }

	vector<int> GetCtlSequence() { return CtlSequence; }

	int GetDataNum() { return DataNum; }
	int GetCtlNum() { return CtlNum; }
	int GetDegree() { return Degree; }
	int GetPosNum() { return PosNum; }
	double GetPresentError() { return PresentError; }
	double GetTargetError() { return TargetError; }
	vector<Cpoint> GetDifferenceVector() { return DifferenceVector; }

	void loadDataFromFile(QString FileName);
	void SetPoiNum(const int &a) { DataNum = a; }
	void SetCtlNum(const int &a) { CtlNum = a; }
	void SetDegree(const int &a) { Degree = a; }
	void SetPosNum(const int &a) { PosNum = a; }
	void SetKnotVector(const vector<double> &a) { KnotVector = a; }
	void SetCtlPoints(const vector<Cpoint> &a) { CtlPoints = a; }
	void SetDataPoints(const vector<Cpoint> &a) { DataPoints = a; }
	void SetDataParameters(const vector<double> &a) { DataParameters = a; }
	void SetCtlSequence(const vector<int> &a) { CtlSequence = a; }
	void SetTargetError(const double &a) { TargetError = a; }

	void CalculateKnotVector();		// Calculate the knot vector
	void CalculateDataParameter();	// Calculate the data parameters
	void CalculateCtlSequence();	// Calculate the contrl points sequence
	void CalculateCurvePoints();	// Calculate the points on the curve
	void CalculateDataPointsOnCurve();

	void Normalize();				// Normalize the data point to (-1, -1) - (1, 1)

	void CalculateCtlPoints();		// Calculate the control points
	Cpoint CalculateOnePoint(double u);	//Calculate one point for parameter u

	void CalculatePresentError();
	void CalculateDifferenceVector();

	void OnePIAIterateStep();

	Eigen::Vector3d CalculateFirstDerivative(double u);
	Eigen::Vector3d CalculateSecondDerivative(double u);


private:
	vector<Cpoint> CtlPoints;	// Control points for curve
	vector<Cpoint> DataPoints;	// The data points
	vector<Cpoint> DataPointsOnCurve;	// [t0, t1, t2, ... , tn] on curve
	vector<double> KnotVector;	// Knot vector for curve
	vector<double> DataParameters;	// The data parameter
	vector<int> CtlSequence;	// The contrl points sequence
	vector<Eigen::Vector3d> DifferenceVector;	// The difference vector
	vector<Cpoint> PointsOnCurve;   //The points on the curve
	int DataNum;	// DataNum+1 is the number of data points(P0...Pn)
	int Degree;	// The degree of basis functions.
	int CtlNum;	// CtlNum+1 is the number of contrl points
	int PosNum;	// PosNum+1 is the number of points on curve
	double Max;
	double Min;
	double Mid;
	double PresentError;	// Present fitting error
	double TargetError;		// Final fitting error we want
};
