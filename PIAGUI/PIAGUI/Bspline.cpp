#include "Bspline.h"

int Bspline::FindSpan(int n, int p, double u, vector<double> U)
{
	//二分法确定u所属区间下标(非周期节点矢量）
	//n+1为控制点数，p为基函数次数，U为节点划分
	if (u == U[n + 1])
		return(n);
	int low = p;
	int high = n + 1;
	int mid = (low + high) / 2;
	while (u < U[mid] || u >= U[mid + 1])
	{
		if (u < U[mid])
			high = mid;
		else
			low = mid;
		mid = (low + high) / 2;
	}
	return(mid);
}

double*  Bspline::BasisFuns(int i, double u, int p, vector<double> U)
{
	//计算所有非零B样条基函数的值
	//i为对应u所属的区间下标，p为基函数的次数，U为对应的节点矢量
	double* N = new double[p + 1];
	double* left = new double[p + 1];
	double* right = new double[p + 1];
	double saved, temp;
	N[0] = 1.0;
	for (int j = 1; j <= p; j++)
	{
		left[j] = u - U[i + 1 - j];
		right[j] = U[i + j] - u;
		saved = 0.0;
		for (int r = 0; r < j; r++)
		{
			temp = N[r] / (right[r + 1] + left[j - r]);
			N[r] = saved + right[r + 1] * temp;
			saved = left[j - r] * temp;
		}
		N[j] = saved;

	}

	delete[] left;
	delete[] right;
	return N;
}