#include<iostream>
using namespace std;
int main()
{
int n,i,j,a[50],min,m;

cout<<"Enter number of values:";
cin>>n;

cout<<"Enter the values:";
for(i=0;i<n;i++)
cin>>a[i];

cout<<"Enter 1 for bubble sort and 2 for selection sort";
cin>>m;

switch (m)
{
case 1:
  
	for(i=1;i<(n-1);i++)
	{
	  for(j=0;j<(n-i);j++)
	   {
	   if(a[j]>a[j+1])
	    swap(a[j],a[j+1]);
	   }
	}
  
break;
case 2:

		for(i=0;i<(n-1);i++)
		{
		min=i;
		for(j=(i+1);j<n;j++)
		if(a[j]<a[min])
		min=j;
		swap(a[i],a[min]);
		}
	     

}


cout<<"Sorted list is:"<<endl;
		for(i=0;i<n;i++)
		cout<<a[i]<<endl;
return 0;
}
