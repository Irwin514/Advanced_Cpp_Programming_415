/*
	Question 1 ************************************
	The simulation of a 2nd order differential equation given by x=x+fdt can 
	be approximated  using the Euler simulation method given by ,  where 
	Note  is the position and  is the velocity.  Evaluate the Euler 
	simulation equation indicated above with the initial conditions ,  
	at  and repeatedly using an infinite while loop and suitable arrays to 
	represent the vectors.  Print the variables  to the screen each 
	time through the loop followed by a new line.
	
	Set the following initial conditions to each variable
	x[1]=x
	x[2]=y
	x[1]=1
	x[2]=0
	t=0
	dt=0.001

*/

#include<iostream>
#include<cmath>
#include<conio.h>
#include<fstream>
using namespace std;

//question 1*** 

int main()
{	int i;					//i variable for for(i;i;i) to verify each 
	double x[2+1], f[2+1];		//Euler simulation variables
	double t, dt;			//t, dt time variable
	
	//Setting the initial conditions
	x[1]=1.0;
	x[2]=0.0;
	t=0.0;
	dt=0.001;
	
	while(1)				//infinite while loop
		{	cout<<" --> "<<x[1]<< " --> "<<x[2]<< " --> "<<t <<"\n"	;	//time variable
		
			//calculate f1 & f2
			f[1]=x[2];
			f[2]=-x[1]-x[2] +sin(t);
			
			//Euler simulation with for loop
			for(i=1;i<=2;i++)
				{ x[i]=x[i]+ f[i]*dt;
				}
			t=t+dt;
			
		}
	return 0;
}
