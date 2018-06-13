#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void forkmet()
{
	int var=0;
	int f=fork();
	if(f<0)
	{
		perror("Fork error");
	}
	if(f==0)
	{
		var=var+10;
		printf("\nI am child with pid:%d and parent:%d and var=%d",getpid(),getppid(),var);
	//	printf("\nValue of var=%d",var);
	}
	else{
		var=20;
		printf("\nI am parent whose child has pid:%d and var=%d",f,var);
	//	printf("\n Value of var=%d",var);
	}
}

void waitmet()
{
	int status;
	int f=fork();
	if(f<0)
	{
		perror("Fork error");
	}
	else if(f==0)
	{
		printf("\nI am child with pid:%d and parent:%d ",getpid(),getppid());
		printf("TErminating child...");
		//sleep(3);
		exit(1);
		
	}
	else{
		printf("\nI am parent whose child has pid:%d ",f);
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("\nChild has terminated with status: %d",WEXITSTATUS(status));
		}
	}
}

void exemet()
{
	char *args[]={"./EXEC",NULL};
	execvp(args[0],args);
	printf("This line will be ignored..");
}

int main()
{
	int ch;
	printf("\nEnter 1 for fork.\nEnter 2 for wait.\nEnter 3 for exec.");
	scanf("%d",&ch);
	if(ch==1){
		forkmet();
	}
	else if(ch==2){
		waitmet();
	}
	else if(ch==3){
		exemet();
	}
	//forkmet();
	//waitmet();
	//exemet();
	return 0;
}
