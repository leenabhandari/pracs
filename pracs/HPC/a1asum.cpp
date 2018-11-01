#include<stdio.h>
#include<omp.h>

int main()
{
	double arr[10],b[10];
	//omp_set_num_threads(4);
	double sum=0;

	for(int i=0;i<10;i++)
	{
		arr[i]=i+2.0;
		b[i]=i*1.0;
	}

	#pragma omp parallel for reduction(+:sum)

	for(int i=0;i<10;i++)
	{
		printf(" i=%d\n",i);
		sum+=arr[i]+b[i];
	}

	printf("Sum=%f",sum/10);
	return 0;
}
