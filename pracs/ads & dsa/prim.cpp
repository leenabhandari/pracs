#include<iostream>
using namespace std;

void create()
{
    int n,i,j,a[10][10],visit[10]={0};
    string name[10];
    cout<<"Enter number of offices:";
    cin>>n;
    cout<<"Enter the names: ";
    for(i=0;i<n;i++)
        cin>>name[i];
    cout<<"Enter data: ";
    for(i=0;i<n;i++)
    {
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
    }

    cout<<"\n";
    for(i=0;i<n;i++)
        cout<<name[i]<<"\t";
    cout<<"Entered data is: \n ";
    for(i=0;i<n;i++)
    {
        cout<<name[i]<<"\t";
          for(j=0;j<n;j++)
    {
        cout<<a[i][j]<<"\t";
    }
    cout<<endl;
    }

    visit[0]=1;
    cout<<name[0]<<"\t";
    int min,row,col=0,k,cos=0;
    for( k=0;k<n;k++)
		{
			min=999;
			for(i=0;i<n;i++)
			{
				for(j=0;j<=n;j++)
				{
					if(visit[i]==1&&visit[j]==0)
					{
                    if(a[i][j]!=-1 && min>a[i][j])
                    {
                        min=a[i][j];
                        row=i;
                        col=j;
                    }

                    }
                }
            }
        cos=cos+min;
        cout<<name[col]<<"\t";
        a[row][col]=-1;
        a[col][row]=-1;
        visit[col]=1;

    }
    cout<<"cost: "<<cos;

}



int main()
{

    create();
    return 0;
}
