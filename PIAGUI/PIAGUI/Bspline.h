#pragma once

//#include "Mathematic.h"
//#include "PIAGUI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "include\Eigen\Core"
#include <vector>
typedef Eigen::Vector3d Cpoint;
using namespace std;

extern int Method;

class Bspline
{
public:
	Bspline() {};
	virtual ~Bspline() {};
	
	int FindSpan(int n, int p, double u, vector<double> U);
	double* BasisFuns(int i, double u, int p, vector<double> U);

private:
	
};


class Surface
{
public:
	Surface() {}
	~Surface() {}

private:

};