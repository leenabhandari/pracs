#include<iostream>
#include<omp.h>
#include<queue>
using namespace std;

int BFS(int a[10][10],int key,int val[10],int v)
{
	int loc=-1;
	queue<int> Q;
	int visited[10]={};
	//int count=0;
	
	visited[0]=1;
	if(key==val[0])loc=0;
	
	Q.push(0);
	
	
	while(!Q.empty())
	{
		int cur=Q.front();
		Q.pop();
		omp_set_num_threads(3);
		#pragma omp parallel for
		for(int i=0;i<v;i++)
		{
		
		cout<<"Thread id: "<<omp_get_thread_num()<<"\n";
		//cout<<endl;
			
			//cout<<omp_get_thread_num()<<" !\t";
			
			if(a[i][cur]==1 && visited[i]!=1)
			{
				#pragma omp critical
				{
					Q.push(i);
					visited[i]=1;
					if(key==val[i])loc=i;
				}
			}
		}	
	}
	
	return loc;
	
}

int main()
{
	int v,e,a[10][10]={},x,val[10]={};
	cout<<"Enter number of nodes and number of edges: ";
	cin>>v>>e;
	cout<<"Enter edges:";
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	
	cout<<"Enter values: ";
	for(int i=0;i<v;i++)cin>>val[i];
	
	cout<<"Enter key: ";
	cin>>x;
	
	int loc=BFS(a,x,val,v);
	if(loc==-1)cout<<"Key not found";
	else cout<<"Key found at "<<loc;
	return 0;
	
}

/*
Enter number of nodes and number of edges: 5 4
Enter edges:0 3
0 4
1 4
2 4
Enter values: 3
10
8
2
6
Enter key: 6
Thread id: 2
Thread id: 0
Thread id: 0
Thread id: 1
Thread id: 1
Thread id: 0
Thread id: 0
Thread id: 2
Thread id: 1
Thread id: 1
Thread id: 0
Thread id: 0
Thread id: 2
Thread id: 1
Thread id: 1
Thread id: 0
Thread id: 0
Thread id: 2
Thread id: 1
Thread id: 1
Thread id: 0
Thread id: 0
Thread id: 2
Thread id: 1
Thread id: 1
Key found at 4 */

