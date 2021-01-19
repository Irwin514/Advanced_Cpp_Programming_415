
#include <iostream>
#include <cmath> 
#include <fstream>
#include "ran.h"
#include "Nnetwrk.h"



void calculate_outputs(Layer &layer, Layer &layer_p)
{
	int i, j, n, m;
	double net;
	-n = layer.N_node; // number of nodes in the current layer
	m = layer_p.N_node; // number of nodes in the previous layer	

	for (i = 1; i <= n; i++)
	{
		net = layer.w[i][0];
		for (j = 1; j <= m; j++)	{
			net += layer.w[i][j] * layer_p.Output[j];
		}
		layer.Output[i] = 1 / (1 + exp(-net));
	}

}

Layer::Layer(int n_node)
{
	int i, j, m;
	long int s1 = -7;
	N_node = n_node;

	for (i = 1; i <= N_node; i++) Output[i] = 0.0;

	for (i = 1; i <= N_node; i++)
		{	m = N_MAX - 1;
			for (j = 0; j <= m; j++)
					{
						w[i][j] = i - j + 0.5; // for testing
					}
		}

}



neural_network::neural_network(int n_l, int n_node[])
{
	N_L = n_l;
	N_in = n_node[1];
	N_out = n_node[N_L];

	for (int i = 1; i <= sizeof(n_node); i++)
		{	Lp[i] = new Layer(n_node[i]);
		}

}


// N_node[L] is a 1D array (L = 1 to N_L) that represents the number
// of nodes in layer L (L=1 is input layer, L = N_L is output layer)

neural_network::~neural_network()
{
	for (int i = 1; i <= N_L; i++)
		{
			delete Lp[i];
		}
}


void neural_network::calculate_network_outputs()
{	for (int i = 1; i <= N_in; i++)
			{	Lp[1]->Output[i] = In[i];
				std::cout << "n_in: " << N_in << std::endl;
			}

	for (int i = 1; i < N_L; i++)
			{	calculate_outputs(*Lp[i], *Lp[i + 1]);
			}
	
	for (int j = 1; j <= N_out; j++) Out[j] = Lp[N_L - 1]->Output[j];

}