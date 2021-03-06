#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	const int N = 50;
	int Nt;
	double Tfin = 50.;
	double g = 500000.;
	double beta = 0.25;
	double Ra = 0.1;
	double Rb = 0.35;
	double Tb = 100.;
	double T0;
	T0 = Tb;
	double z;
	z = (Rb - Ra) / N;
	double T[N + 1];
	double TN[N + 1];
	double Qa = -2000.;
	double k = 40.;
	double Ar;
	double alfa =1.2e-3;
	double delta = (beta * z * z) / alfa;
	Nt = Tfin / delta;
	
	for (size_t i = 0; i <= N; i++)
	{
		T[i] = T0;
	}
	for (size_t it = 1; it <= Nt; it++)
	{
		for (size_t i = 1; i <= N; i++)
		{
			TN[i] = T[i] * (1. - 2. * beta) + T[i - 1] * beta * (1. - z / (Ra + i * z)) + T[i + 1] * beta * (1. + z / (Ra + i * z)) + (beta * z * z * g) / k;
		}
		
		TN[0] = T[1] + (2. * z * Qa) / k;
		
		TN[N] = Tb;
		//TN[N] = T[N] * (1. - 2. * beta) + T[N - 1] * beta * (1. - z / Rb) + Ar * beta * (1. + z / Rb) + (beta * z * z * g) / k;
		
		for (size_t i = 0; i <= N; i++)
		{
			T[i] = TN[i];
		}
	}

	ofstream XLS("results.csv", ios::trunc);

	if (!XLS.good()) {
		printf("Can't open file to erite!\n");
		system("pause");
	}

	for (size_t i = 0; i <= N; i++)
	{
		string number = std::to_string(T[i]);
		replace(number.begin(), number.end(), '.', ',');
		XLS << i << ";" << number << endl;

		printf("T[%d] = %lf \n", i, T[i]);
	}

	XLS.close();

	printf("\n");
	system("pause");
	return 0;
}