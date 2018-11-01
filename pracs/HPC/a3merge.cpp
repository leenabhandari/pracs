#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void merger(int a[10],int i1,int j1,int i2,int j2)
{
	int temp[10];
	int x=i1;
	int y=i2;
	int k=0;
	
	while(x<=j1 && y<=j2)
	{
		if(a[x]<a[y])
		{
			temp[k++]=a[x++];
		}
		else{
			temp[k++]=a[y++];
		}
	}
	
	while(x<=j1)
	{
		temp[k++]=a[x++];
	}
	
	while(y<=j2)
	{
		temp[k++]=a[y++];
	}
	
	for(int p=i1,q=0;p<=j2;p++,q++)
	{
		a[p]=temp[q];
	}
}


void merge(int a[50],int i,int j)
{
	int mid=(i+j)/2;
	
	if(i<j)
	{
		//omp_set_num_threads(4);
		#pragma omp parallel sections
		{
			//omp_set_num_threads(4);
			#pragma omp section
			//#pragma omp task firstprivate(a,i,j)
			{
				//cout<<"\n1st section";
				//cout<<omp_get_thread_num()<<" 1\n";
				merge(a,i,mid);
			}
			
			#pragma omp section
			//#pragma omp task firstprivate(a,i,j)
			{
				//cout<<"\n2nd section";
				//cout<<omp_get_thread_num()<<" 2\n";
				merge(a,mid+1,j);
			}
		}
	}
	
	//#pragma omp taskwait
	merger(a,i,mid,mid+1,j);
}

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<"\t";
	}
	cout<<endl<<endl;
	
	merge(a,0,9);
	
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<"\t";
	}
}
