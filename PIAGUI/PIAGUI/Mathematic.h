#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Cpoint
{
public:
	double x;
	double y;
	double z;
	Cpoint(double _x = 0, double _y = 0, double _z = 0) :x(_x), y(_y), z(_z)//构造函数
	{}
	//~Cpoint();//析构函数

	Cpoint(const Cpoint& p) :x(p.x), y(p.y), z(p.z)//拷贝构造函数 
	{}
	const Cpoint operator*(double a)//数乘
	{
		this->x = this->x*a;
		this->y = this->y*a;
		this->z = this->z*a;
		return *this;

	}


	const Cpoint& operator-(const Cpoint& p)//减法函数
	{
		this->x -= p.x;
		this->y -= p.y;
		this->z -= p.z;
		return *this;
	}

	const Cpoint& operator=(const Cpoint& p)//赋值函数
	{
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		return *this;
	}

	int operator==(const Cpoint& p)//两点坐标相等判断
	{
		return !((this->x != p.x) || (this->y != p.y) || (this->z != p.z));
	}

	int operator!=(const Cpoint& p)
	{
		return (this->x != p.x) || (this->y != p.y) || (this->z != p.z);
	}

	friend ostream& operator<<(ostream& out, Cpoint& p);
};

//class Bspline
//{
//public:
//	Bspline() {};
//	~Bspline() {};
//	virtual Cpoint CalculateOnePoint(double u) { throw"You haven't define the CalculateOnePoint function!"; }
//
//	double* BasisFuns(int i, double u, int p, vector<double> U);
//	int FindSpan(int n, int p, double u, vector<double> U);
//	//int GetPoiNum() { return n; }
//	//int GetDegree() { return k; }
//	//vector<double> GetKnotVector() { return U; }
//
//private:
//	//int n;	// n+1 is the number of control points(P0...Pn)
//	//int k;	// The degree of basis functions.
//	//vector<double> U;	// The knot vector
//};