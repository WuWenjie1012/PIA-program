#pragma once
#include "Bspline.h"
#include "include\Eigen\Core"
#include "include\Eigen\Dense"
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

	Eigen::MatrixXd GetCtlPoints() { return CtlPns; }
	vector<Cpoint> GetDataPoints() { return DataPoints; }
	vector<Cpoint> GetCurvePoints() { return PointsOnCurve; }
	Eigen::MatrixXd GetDifferenceVector() { return Diff; }
	vector<Cpoint> GetFirstDerivative() { return FirstDerivativeOnCurve; }
	vector<double> GetCurvature() { return CurvatureOnCurve; }

	vector<int> GetCtlSequence() { return CtlSequence; }

	int GetDataNum() { return DataNum; }
	int GetCtlNum() { return CtlNum; }
	int GetDegree() { return Degree; }
	int GetPosNum() { return PosNum; }
	double GetPresentError() { return PresentError; }
	double GetTargetError() { return TargetError; }

	void loadDataFromFile(QString FileName);
	void SetPoiNum(const int &a) { DataNum = a; }
	void SetCtlNum(const int &a) { CtlNum = a; }
	void SetDegree(const int &a) { Degree = a; }
	void SetPosNum(const int &a) { PosNum = a; }
	void SetKnotVector(const vector<double> &a) { KnotVector = a; }
	Eigen::MatrixXd SetCtlPoints(const Eigen::MatrixXd &a) { CtlPns = a; }
	void SetDataPoints(const vector<Cpoint> &a) { DataPoints = a; }
	void SetDataParameters(const vector<double> &a) { DataParameters = a; }
	void SetCtlSequence(const vector<int> &a) { CtlSequence = a; }
	void SetTargetError(const double &a) { TargetError = a; }
	void SetIteType(const int &a) { IteType = a; }

	void CalculateKnotVector();		// Calculate the knot vector
	void CalculateDataParameter();	// Calculate the data parameters
	void CalculateCtlSequence();	// Calculate the contrl points sequence
	void CaclculateParametersOnCurve();	// Calculate parameters for points on curve
	void CalculateCurvePoints();	// Calculate the points on the curve
	void CalculateDataPointsOnCurve();

	void Normalize();				// Normalize the data point to (-1, -1) - (1, 1)

	void CalculateCtlPoints();		// Calculate the control points
	Cpoint CalculateOnePoint(double u);	//Calculate one point for parameter u

	void CalculatePresentError();
	void CalculateDifferenceVector();

	void OneIterateStep();
	// Functions for first and second derivative
	Eigen::MatrixXd CalculateQCtlPoints(Eigen::MatrixXd ctlpns, vector<double> knotvector, int degree);
	Eigen::MatrixXd CalculateRCtlPoints(Eigen::MatrixXd ctlpns, vector<double> knotvector, int degree);
	Eigen::Vector3d CalculateOneFirstDerivative(double u, Eigen::MatrixXd qctlpoints, vector<double> knotvector, int degree);
	Eigen::Vector3d CalculateOneSecondDerivative(double u, Eigen::MatrixXd rctlpoints, vector<double> knotvector, int degree);
	void CalculateFirstDerivativeOnCurve();
	void CalculateSecondDerivativeOnCurve();
	void CalculateCurvatureOnCurve();

	void Init();	// Init for iteration

	void CalculateConfigurationMatrixA();	
	void CalculateMatrixD1();
	void CalculateMatrixD2();
	void CalculateMatrixMc();
	void CalculateMatrixMe();

private:
//	vector<Cpoint> CtlPoints;	// Control points for curve
	Eigen::MatrixXd QCtlPoints;	// Control points for first derivative curve
	Eigen::MatrixXd RCtlPoints;	// Control points for second derivative curve
	vector<Cpoint> DataPoints;	// The data points
	//vector<Cpoint> DataPointsOnCurve;	// [t0, t1, t2, ... , tn] on curve
	vector<double> KnotVector;	// Knot vector for curve
	vector<double> DataParameters;	// The data parameter

	vector<double> CurvatureOnCurve;	// Carvature for points on curve
	vector<Cpoint> FirstDerivativeOnCurve;	// First derivative
	vector<Cpoint> SecondDerivativeOnCurve;	// Second derivative

	vector<int> CtlSequence;	// The contrl points sequence
	//vector<Eigen::Vector3d> DifferenceVector;	// The difference vector
	vector<Cpoint> PointsOnCurve;   //The points on the curve
	vector<double> ParametersOnCurve;	// Parameters for points on curve
	int DataNum;	// DataNum+1 is the number of data points(P0...Pn)
	int Degree;	// The degree of basis functions.
	int CtlNum;	// CtlNum+1 is the number of contrl points
	int PosNum;	// PosNum+1 is the number of points on curve
	double Max;
	double Min;
	double Mid;
	double PresentError;	// Present fitting error
	double TargetError;		// Final fitting error we want

	int IteType;	// 0 - PIA, 1 - LSPIA

	Eigen::MatrixXd A;	// Configuration Matrix
	Eigen::MatrixXd CtlPns;	// Control points
	Eigen::MatrixXd DataPns;	// Data points
	Eigen::MatrixXd Diff;	// The difference vector
	Eigen::MatrixXd miu;


	Eigen::MatrixXd D1;	// P' = D1 * P
	Eigen::MatrixXd D2;	// P'' = D2 * P
	Eigen::MatrixXd Mc;	// Curvature matrix
	Eigen::MatrixXd Me;	// Two order difference matrix of curvature 
	Eigen::MatrixXd pCtlPos;	
//	Eigen::MatrixXd 
};
