#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
	int a[100],b[100],c[100];
	omp_set_num_threads(4);
	#pragma omp parallel for
	for(int i=0;i<100;i++)
	{
		a[i]=rand()%1000;
		b[i]=rand()%1000;
	}
	
	#pragma omp parallel for
	for(int i=0;i<100;i++)
	{
		c[i]=a[i]+b[i];
		printf("Thread id:%d, for i=%d a[i]=%d, b[i]=%d, c[i]=%d\n",omp_get_thread_num(),i,a[i],b[i],c[i]);
	}
	
}
