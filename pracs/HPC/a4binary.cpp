#include<iostream>
#include<omp.h>
using namespace std;

int bin(int a[10],int key,int i,int j)
{
	int mid=(i+j)/2;
	int loc=-1;
	
	if(key==a[mid])loc=mid;
	
	//omp_set_num_threads(2);
	#pragma omp parallel sections
	{
		omp_set_num_threads(2);
		#pragma omp section
		if(key<a[mid])
		{
			cout<<omp_get_thread_num()<<" 1\n";
			{
			loc=bin(a,key,i,mid);
			}
		}
		#pragma omp section
		if(key>a[mid])
		{
			cout<<omp_get_thread_num()<<" 2\n";
			{
			loc=bin(a,key,mid+1,j);
			}
		}
	
	}
	return loc;
}



int main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	
	int loc=bin(a,9,0,9);
	if(loc==-1)
	{
		cout<<"key not found"<<endl;
	}
	else cout<<"Key found at loc "<<loc;
}
