#include<iostream>
#include<omp.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int mat[6][5],vec[5],res[6];
	int row=6,col=5;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			mat[i][j]=rand()%10;
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	for(int i=0;i<col;i++)
	{
		vec[i]=rand()%10;
		cout<<vec[i]<<endl;
	}
	
	#pragma omp parallel for 
	
	for(int i=0;i<row;i++)
	{
		res[i]=0;
		for(int j=0;j<col;j++)
		{
			res[i]+=mat[i][j]*vec[j];
			
		}
		
		cout<<res[i]<<"\t Thread id: "<<omp_get_thread_num()<<endl;;
	}
	return 0;
}
