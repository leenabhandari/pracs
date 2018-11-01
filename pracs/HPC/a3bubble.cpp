#include<iostream>
#include<omp.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int arr[10];
	for(int i=0;i<10;i++)
	{
		arr[i]=rand()%100;
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	
	omp_set_num_threads(4);
	
	for(int i=0;i<9;i++)
	{
		#pragma omp parallel for shared(arr,i)
		for(int j=0;j<9-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
			cout<<"Thread id:"<<omp_get_thread_num()<<" i="<<i<<" j="<<j<<endl;
		}
	}
	
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<"\t";
	}
	
}
