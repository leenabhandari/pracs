/*Write C++ program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using quick sort */


#include<iostream>
using namespace std;
void quick(int,int,float*);
int partition(int low, int high, float *a)
{
 	float pivot=a[low];
	
        
	int l=low,h=high;
       
   
	while (l<h)
	{
		while(a[l]<pivot)
		l++;
		while(a[h]>pivot)
		h--;
		if(l<h)
		swap(a[l],a[h]);
	}
	swap(pivot,a[h]);
	return h;
	
}

void quick(int l,int h,float *a)
	{
		int index;
		if(l<h)
		{
		index=partition(l,h,a);
		quick(l,index-1,a);
		quick(index+1,h,a);
	        }
        }
 

int main()
	{
		float a[100];
		int n,p,m,i;
		cout<<"Enter number of students:";
		cin>>n;
		cout<<"Enter percentages:";
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<"Entered values are:";
		for(i=0;i<n;i++)
		cout<<a[i]<<endl;
		p=n-1;
		m=0;
		quick(m,p,a);
		cout<<"After sorting:";
		for(i=0;i<n;i++)
		cout<<a[i]<<endl;
		return 0;
        }
