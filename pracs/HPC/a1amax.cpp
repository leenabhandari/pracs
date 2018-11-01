#include<stdio.h>
#include<omp.h>

int main(){
	double arr[10];
	omp_set_num_threads(4);
	
	double max_val=0;
	for(int i=0;i<10;i++)
	{
		arr[i]=2.0+i;
	}	
	
	#pragma omp parallel for reduction(max:max_val)
	
	for(int i=0;i<10;i++)
	{
		printf("thread:%d and i=%d\n",omp_get_thread_num(),i);
		if(max_val<arr[i])max_val=arr[i];
	}
	
	printf("maximum value=%f",max_val);
	return 0;
}

