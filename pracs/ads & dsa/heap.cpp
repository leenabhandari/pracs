#include<iostream>
using namespace std;
void minheap(int a[],int i,int n);
int main()
{
    int n,i,a[10];
    cout<<"\n Enter number of students: ";
    cin>>n;
    cout<<"\n Enter their marks: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"\n Entered marks are: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;

    for(i=n/2;i>=0;i--)
    {
        minheap(a,i,n);
    }
    cout<<"\n Min heap: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
    cout<<"Smallest value: "<<a[0];

    return 0;
}

void maxheap(int a[10],int i,int n)
{
    int l,r,large;
    l=(2*i)+1;
    r=(2*i)+2;
    if(l<n && a[l]>a[i])
        large=l;
    else large=i;
    if(r<n && a[r]>a[large])
        large=r;
    if(large!=i)
    {
        swap(a[large],a[i]);
        maxheap(a,i,n);
    }
}

void minheap(int a[],int i,int n)
{
    int l=(2*i)+1;
    int r=(2*i)+2;
    int small;
    if(l<n && a[l]<a[i])
        small=l;
    else small=i;
    if(r<n && a[r]<a[small])
        small=r;
    if(small!=i)
    {
        swap(a[i],a[small]);
        minheap(a,i,n);
    }
}
