#pragma once

#include "Mathematic.h"
//#include "PIAGUI.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Bspline
{
public:
	Bspline() {};
	virtual ~Bspline() {};
	
	int FindSpan(int n, int p, double u, vector<double> U);
	double* BasisFuns(int i, double u, int p, vector<double> U);

private:
	vector<Cpoint> PointOnObject;
	
};


class Surface
{
public:
	Surface() {}
	~Surface() {}

private:

};