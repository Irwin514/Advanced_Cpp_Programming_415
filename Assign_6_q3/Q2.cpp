
#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
#define Pi atan(1)*4


void calculate_Xd(const double x[], double t, int N, double xd[], int M, double u[])
		{									
			xd[1] = u[1] * cos(x[3] * PI / 180);  // dx=us*cos(theta)
			xd[2] = u[1] * sin(x[3] * PI / 180); // dy=us*sin(theta)
			xd[3] = u[2];
		}

int main()
{
	const int N = 3; // number of state variables
	const int M = 2; // number of inputs

	int i;
	double t; // current time (seconds)
	double dt; // time step (s)
	double tf; // final time (s)
	double x[N + 1];  // state vector
	double xd[N + 1]; // derivative vector at time t
	double u[M + 1]; // input vector u

	ofstream fout("sim3.csv"); // output file

	fout << scientific;

	fout.precision(7);

	t = 0.0; // initial time (s)

	x[1] = 0.0;
	x[2] = 0.0;
	x[3] = 3.14159 / 4 * 0; // theta = 45 deg

	dt = 0.001; // time step

	tf = 10.0; // final time (s)

	while (t < tf) {

		// save time and states into a file
		fout << t;
		for (i = 1; i <= N; i++) fout << "," << x[i];

		// calculate the inputs
		u[1] = 1.0; // us - forward speed
		u[2] = 1.0;	// uw - turning angular velocity

		// calculate the derivative vector at time t
		xd[1] = u[1] * cos(x[3]);
		xd[2] = u[1] * sin(x[3]);
		xd[3] = u[2];

		calculate_Xd(x, t, N, xd, M, u);

		// Euler's equation
		for (i = 1; i <= N; i++) x[i] = x[i] + xd[i] * dt;

		t = t + dt; // increment time

		if (t<tf) fout << "\n";

	}

	fout.close();

	return 0;
}