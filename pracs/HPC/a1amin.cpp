#include<stdio.h>
#include<omp.h>

int main()
{
	double arr[10];
	omp_set_num_threads(4);
	double mini=999;

	for(int i=0;i<10;i++)
	{
		arr[i]=i+2.0;
	}

	#pragma omp parallel for reduction(min:mini)

	for(int i=0;i<10;i++)
	{
		printf("thread id:%d, i=%d\n",omp_get_thread_num(),i);
		if(mini>arr[i])
		{
			mini=arr[i];
		}
	}

	printf("Minimum value=%f",mini);
	return 0;
}
