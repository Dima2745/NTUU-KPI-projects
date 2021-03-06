#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<math.h>
#include<iomanip>

using namespace std;

double f_tocn(double x)
{
	return 2 * exp(x) / (1 + exp(x)*(cos(x) + sin(x)));
}

double func(double x, double y)
{
	return y - y * y*cos(x);
}

void RKF3(double h)
{
	double a = 0.0, b = 2.1;

	double *y = new double[((b - a) / h) + 1];
	double *k0 = new double[((b - a) / h) + 1];
	double *k1 = new double[((b - a) / h) + 1];
	double *k2 = new double[((b - a) / h) + 1];
	double *k3 = new double[((b - a) / h) + 1];
	
	double *y_tocn = new double[((b - a) / h) + 1];


	int i = 0;
	y[i] = 1.0;

	cout << "\n\t\t\t\t\t***** RUNGE-KUTTA-FELBERGA 3 *****" << endl;
	cout << endl;
	cout << "\t";
	for (int i = 1; i <89; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << "\t| " << setw(5) << "x" << setw(15) << "y(x)" << setw(15) << "y" << setw(25) << "y(x)-y" << setw(26) << "100e/y|" << endl;
	cout << "\t";
	for (int i = 1; i <89; i ++)
	{
		cout << "-";
	}
	cout << endl;
	
	for (double xp = a; xp <= b; xp += h, i++)
	{
		k0[i] = h * func(xp, y[i]);
		k1[i] = h * func(xp + h / 4, y[i] + k0[i] / 4);
		k2[i] = h * func(xp + h * (4 / 9.), y[i] + k0[i] * (4 / 81.) + k1[i] * (32 / 81.));
		k3[i] = h * func(xp + h * (6 / 7.), y[i] + k0[i] * (57 / 98.) - k1[i] * (437 / 343.) + k2[i] * (1053 / 686.));
		
		y_tocn[i] = f_tocn(xp);
		y[i + 1] = y[i] + k0[i] * 1 / 6. + k2[i] * 27 / 52. + k3[i] * 49 / 156.;

		cout<<"\t| " <<setw(5)<< xp << setw(15) << y_tocn[i] << setw(15) << y[i] << setw(25) << y_tocn[i] - y[i] << setw(25) << (100 * (y_tocn[i] - y[i])) / y[i] <<"|"<< endl;
	}

	cout << "\t";
	for (int i = 1; i <89; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void RK4(double h)
{
	double a = 0.0, b = 2.1;
	
	double *y = new double[((b-a)/h)+1];
	double *k1 = new double[((b - a) / h) + 1];
	double *k2 = new double[((b - a) / h) + 1];
	double *k3 = new double[((b - a) / h) + 1];
	double *k4 = new double[((b - a) / h) + 1];
	double *y_tocn = new double[((b - a) / h) + 1];
	
	
	int i = 0;
	y[i] = 1.0;
	
	cout << "\t\t\t\t\t***** RUNGE-KUTTA 4 *****" << endl;
	cout << endl;
	cout << "\t";
	for (int i = 1; i <89; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << "\t| " << setw(5) << "x" << setw(15) << "y(x)" << setw(15) << "y" << setw(25) << "y(x)-y" << setw(26) << "100e/y|" << endl;
	cout << "\t";
	for (int i = 1; i <89; i++)
	{
		cout << "-";
	}
	cout << endl;
	
	for (double xp = a; xp <= b; xp+=h,i++) 
	{
		k1[i] = h * func(xp, y[i]);
		k2[i] = h * func(xp + h / 2, y[i] + k1[i] / 2);
		k3[i] = h * func(xp + h / 2, y[i] + k2[i] / 2);
		k4[i] = h * func(xp + h, y[i] + k3[i]);

		y_tocn[i] = f_tocn(xp);
		y[i + 1] = y[i] + (1 / 6.)*(k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
		
		cout << "\t| " << setw(5) << xp << setw(15) << y_tocn[i] << setw(15) << y[i] << setw(25) << y_tocn[i] - y[i] << setw(25) << (100 * (y_tocn[i] - y[i])) / y[i] << "|" << endl;
	}

	cout << "\t";
	for (int i = 1; i <89; i++)
	{
		cout << "-";
	}
	cout << endl;
}

int main()
{
	double h1=0.2, h2=h1/5, h3=h1/25;
	
	RKF3(0.0001);
	cout << "\n\n\n";
	RK4(h3);

	_getch();
	return 0;
}