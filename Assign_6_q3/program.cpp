
#include <iostream>
#include <cmath> 
#include <fstream>
#include "Nnetwrk.h"
#include "ran.h"
#include "Windows.h"
using namespace std;

int main()
{	int i, N_L;
	int N_node[50];

	// set neural network parameters
	N_L = 3;
	N_node[1] = 3;
	N_node[2] = 3;
	N_node[3] = 3;

	neural_network NN1(N_L, N_node);

	NN1.In[1] = 0.25;
	NN1.In[2] = 0.5;
	NN1.In[3] = 0.75;

	NN1.calculate_network_outputs();

	cout << "\nNETWORK OUTPUT NN1.Out =\n";
	for (i = 1; i <= NN1.N_out; i++) cout << NN1.Out[i] << "\n";
	cout << "\npress to continue.\n";
	getchar();

	return 0;
};

