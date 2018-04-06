#include<iostream>
#include<queue>
using namespace std;
void bfs(int a[10][10],int visit[10],string name[10],int n);
void dfs(int a[10][10],int *visit,string name[10],int n,int k);

void create()
{
    int n,i,j,a[10][10],visit[10]={0};
    string name[10];
    cout<<"Enter number of flights:";
    cin>>n;
    cout<<"Enter the names: ";
    for(i=0;i<n;i++)
        cin>>name[i];
    cout<<"Enter data: ";
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
    {
        if(i==j)
        {
            a[i][j]=-1;
            continue;
        }
        else
        {
            cout<<"\na["<<i<<"]["<<j<<"]=";
        cin>>a[i][j];
        a[j][i]=a[i][j];
        }

    }
    cout<<"\n";
    for(i=0;i<n;i++)
        cout<<name[i]<<"\t";
    cout<<"Entered data is: \n ";
    for(i=0;i<n;i++)
    {
          for(j=0;j<n;j++)
    {
        cout<<a[i][j]<<"\t";
    }
    cout<<endl;
    }
   // bfs(a,visit,name,n);
    dfs(a,visit,name,n,0);
//working one at a time.. either bsf or dfs.
}

void bfs(int a[10][10],int visit[10],string name[10],int n)
{
    queue<string> q;
    q.push(name[0]);
    visit[0]=1;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
    {
        if(visit[i]!=1&&a[k][i]!=-1)
        {
            q.push(name[i]);
            visit[i]=1;
        }
    }

    while(!q.empty())
    {
         cout<<q.front()<<"\t";
         q.pop();
    }
    }

}

void dfs(int a[10][10],int *visit,string name[10],int n,int v)
{

    visit[v]=1;
    cout<<name[v]<<"\t";
    for(int j=0;j<n;j++)
    {
        if(visit[j]!=1 && a[v][j]!=-1)
        {
            dfs(a,visit,name,n,j);
        }
    }
}

int main()
{
    create();
    return 0;
}
