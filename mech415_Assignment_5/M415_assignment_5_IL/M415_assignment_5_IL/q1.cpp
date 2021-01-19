//Question 1 c) Write a regular function (not a member function):

#include<iostream>
#include<cmath>
#include<conio.h>
#include<Windows.h>
#include<Array.h>
#include<Layer.h>
using namespace std;

void calculate_outputs(Layer &layer, Layer &layer_p)
int main()
{



	return 0;
}


void calculate_outputs(Layer &layer, Layer &layer_p)
{
	long double sum = 0.0 , sum2=0.0;
	int i=0, j=0, k=0;

	for (i = 0; i < layer.N_node_c; i++)
	{	for (j = 0; j<layer.N_node_c; j++)
			{ sum += w_c[i][j] * layer.output_c[j] + layer.bias_c[i];
			}
	layer.output_c[i] = 1 / (1 + exp(-1*net))						//ouput formula from pdf lecture notes


}