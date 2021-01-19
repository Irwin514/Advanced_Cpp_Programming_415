/*
			Mech 415 - Advanced programming
			Assignment # 2
			Irwin Lopez
			Student Number: 29372431
*/

#include<iostream>
#include<cmath>
#include<conio.h>
#include<fstream>

//question 2 matrix input 
int compute_array(double M[5+1][5+1], int &nz, int &n7);

//question 3 file save function
int save_array(double M[5+1][5+1],char file_name[]);


using namespace std;
int main ()
		{ 	int i, j;
		
			//Question 1********************************************************
			double x[2+1], f[2+1];
			double t,dt;
			char ch;
			
			x[1]=1.0;			//initial Conditions
			x[2]=0.0;
			t=0.0;
			dt=0.001;
			
			while (1) 			//printing the variables x1,x2, t each time
				{	cout<< t<<"--> "<<x[1]<<"--> "<<x[2]<<"\n"; 
					
					f[1] = x[2];				//Find F
					f[2]= -x[1] -x[2] + sin(t);
					
					for(int i=1 ; i<=2 ; i++)
							{	x[i]= x[i] + f[i]*dt;
							}
					t = t + dt;
				}
				
			//Question 2 function compute_array(M,nz,n7)****************************************
			int nz, n7; 
			double M_1[5+1][5+1];
			compute_array(M_1,nz,n7);
			cout<<nz<<endl;
			cout<<n7;

			//Question 3 function save_array(M, file_name)
			save_array(M_1,"matrix.txt");
			
			//Question 4 function load_array(M, file_name) 
			load_array(M_1, "matrix.txt")
			
			//Question 5 Table read from file
			int n5;
			double *x5, *y5;
			load_table(x5,y5,n5);
			
			cout<<"\n table = \n";
			for( i=1 ; i<=n5 ; i++ )
				{	cout<<x5[i]<<"-->"<<y5[i]<<endl;
				}
		
			
return 0;
		}

//function definition *** Question 2 function
int compute_array(M[5+1][5+1], int &nz, int &n7);
		{	int i, j,
			double min=0; max=0;
			nz=0;
			n7=0;
			const double smallvalue = 1.0e-20;
			
			cout<<"Enter Matrix 5x5 values row by row"
			for(i=1;i<=5;i++)
				{	cout<<"\nrow: "<<i<<"\n";
					for(j=1;j<=5;j++)
						{	
							cin>>M[i][j];
						}
				}
				
			min =  1.0e305 //limit of double is 1.0e308 close to limit 
			max = -1.0e305 //limit of double is -1.0e308 close to limit
			
			for(i=1;i<=5;i++)
				{	for(j=1;j<=5;j++)
						{	if(M[i][j] > 7.0) n7++;
							if(M[i][j] < smallvalue) nz++; 
							if(M[i][j] > max) max = M[i][j]; //keeps track of largest value 
							if(M[i][j] < min) min = M[i][j]; //keeps track of smallest value
						}
				}
						
			if(max>10) && (min<-10)
				{ 	cout<<"Error Matrix - out of range"
					return 1;
				}
			else return 0;
		}
		
		
//function definition saving files***Question 3 
int save_array(double M[5+1][5+1],char file_name[])
	{	int i,j;
		ofstream fout;
		fout.open(file_name);
		
		if (fout== NULL)	
			{	cout<<"Error in saving file";
				return 1;
			}
		
		for(i=1;i<=5;i++)
			for(j=1;j<=5;j++)
				{ fout<<M[i][j]<<"";
				}
			fout<<"\n"
	fout.close();
	
	return 0;		
	}

//function definition laoding a file *** Question 4
int load_array(double M[5+1][5+1], char file_name[]);
	{	int i, j;
		ifstream;
	
		fin.open(file_name);
		if(fin == NULL)
			{	cout<<"\Error to open FILE";
				return 1;
			}
			
		for(i=1;i<=5;i++)
			{ for(j=1;j<=5;j++)
				{	fin>>M[i][j];
				}
			}
		fin.close();
		
		return 0;
	}

//Function definition reading from file .txt format Question 5
int load_table(double * &n5, double * &m5, int &p5 )
	{		int i;
			ifstream fin1;
			char filename[40];
			cout<<"\n Write the Name of the file .txt format";
			cin>>filename;
			
			fin1.open(filename);
			
			if (fin1 == NULL)
					{	"ERROR OPENING THE FILE!";
						return 1;
					}
			
			fin1>>n5;
			cout<<"\n n5"<< n5 <<"\n";
			x5= new double
			y5= new double [n+1;]
			if((x== NULL || y==NULL))
				{	cout<<"ERROR, CHECK TABLE AND TRY AGAIN! ";
					return 1;
				}		
						
		return 0;
	}
			
			
