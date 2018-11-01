#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	int n=5;
	int a[n][n],b[n][n],res[n][n];
	float t;
	clock_t c1,c2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=rand()%1000;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][j]=rand()%1000;
		}
	}
	
	c1=clock();
	#pragma omp parallel for
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			res[i][j]=0;
			for(int k=0;k<n;k++)
			{
				res[i][j]+=a[i][k]*b[k][j];
			}
			cout<<res[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	c2=clock();
	
	t=(float)(c2-c1);
	
	cout<<"Execution time="<<t;
}
