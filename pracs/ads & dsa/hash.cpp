#include<iostream>
using namespace std;

int main()
{
        int cho,a[50],l[50],q[50],key,n;
        cout<<"Enter number of elements:";
        cin>>n;
        cout<<"Enter input numbers: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<10;i++)
        {
            l[i]=-1;
            q[i]=-1;
        }
    do{
    cout<<"Enter 1 for linear and 2 for quadratic and 3 to exit: ";
    cin>>cho;
    switch (cho)
    {
    case 1:
        {
            for(int i=0;i<n;i++)
            {
                key=a[i]%10;
                for(int z=0;z<n;z++)
                {
                    if(l[key]==-1)
                    {
                        l[key]=a[i];
                        break;
                    }
                    else{
                        key++;
                        if(key==10)
                            key=0;
                    }
                }
            }
            cout<<"\nLinear probing: "<<endl;
            for(int z=0;z<10;z++)
                cout<<l[z]<<endl;
            break;
        }

    case 2:
        {
            for(int i=0;i<n;i++)
            {
                key=a[i]%10;
                for(int z=0;z<n;z++)
                {
                    if(q[key]==-1)
                    {
                        q[key]=a[i];
                        break;
                    }
                    else{
                            for(int d=1;d<4;d++)
                            {
                                key=key+(d*d)-((d-1)*(d-1));
                                if(key==10)
                                    key=0;
                                if(q[key]==-1)
                                    break;
                            }
                    }
                }
            }
            cout<<"\nQuadratic probing: "<<endl;
            for(int z=0;z<10;z++)
                cout<<q[z]<<endl;
            break;
        }

    }
    }while(cho!=3);


    return 0;
}
