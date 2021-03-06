#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<math.h>
#include <iomanip>
using namespace std;

#define N 11

double Thomas(double a[], double b[], double c[], double d[], double *t)
{
	for (int i = 2; i <= N; i++) {
		b[i] = b[i] - a[i] * c[i - 1] / b[i - 1];
		d[i] = d[i] - a[i] * d[i - 1] / b[i - 1];
	}

	t[N] = d[N] / b[N];
	
	for (int i = N - 1; i >= 1; i--) {
		t[i] = (d[i] - c[i] * t[i + 1]) / b[i];
	}
	return *t;
}

int main()
{
	double c1 = 1.0, c2 = 0.1, c3 = 0.001;
	double mul = c3;
	double *t = new double [N];
	
	double a[N] = { 0,0,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2 };
	double b[N] = {0, 5.5,5.6,5.7,5.8,5.9,6.0,6.1,6.2,6.3,6.4 };
	
	for (int i = 0; i < N; i++)
	{
		b[i] *= mul;
	}
	double c[N] = { 0,0.5,0.7,0.9,1.1,1.3,1.5,1.7,1.9,2.1};

	//double d[N] = { 0, 2.45, 3.38, 4.30, 5.30, 6.38, 7.54, 8.78, 10.10, 11.50, 9.76 };
	//double d[N] = { 0, 0.470,0.860,1.222,1.646,2.132,2.680,3.290,3.962,4.696,2.272 };
	double d[N] = { 0, 0.25220,0.58280,0.88342,1.24406,1.66472,2.14540,2.68610,3.28682,3.94756,1.44832 };

	*t = Thomas(a, b, c, d, t);
	
	for (int i = 1; i < N; i++)
	{
		//cout <<"\t"<<"x"<<i<<" = "<< setprecision(20) << t[i] << endl;
		printf("\t x%d = %0.20lf\n",i,t[i]);
	}
	_getch();
	return 0;
}