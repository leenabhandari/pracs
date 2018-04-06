/*Write a function template selection Sort. Write a program that inputs, sorts and outputs an
int
eger
array and a float array.*/


#include<iostream>
using namespace std;
int i,j,n;
template<class X>
void selection(X a[50])
{
   int mini,i,j,n;
   X temp;
   cout<<"\n Enter the limit of the array= ";
   cin>>n;
   cout<<"\n Enter the elements.";
   for(i=0;i<n;i++)
   {
      cin>>a[i];
   }
   for (i=0;i<=n-2;i++)
	{
		 mini=i ; 
		for(j=i+1;j<=n-1;j++)
		{
			if (a[j]<a[mini])
			mini=j; 
		} 
		swap(a[i],a[mini]);
	} 
   cout<<"Sorted array is ";
   for(i=0;i<n;i++)
   {
      cout<<"\n"<<a[i];
   }
}  
class Template
{
   private:
   float floatarr[50];
   int intarr[50];
   public:
   void function();
};
void Template::function()
{
   int op;
   char ch;
   do
   {
      cout<<"\n Which is your array?\n 1.Integer\n 2.Float\n";
      cin>>op;
      switch(op)
      {
         case 1:
            selection(intarr);
            break;
         case 2:
            selection(floatarr);
            break;
     }
     cout<<"\n Do you want to continue?(y/n)";
     cin>>ch;
  }while(ch=='y'||ch=='y');
}
int main()
{
   Template obj;
   obj.function();
   return 0;
}

/* Which is your array?
 1.Integer
 2.Float
1

 Enter the limit of the array= 5

 Enter the elements.6
4
3
7
5
Sorted array is 
3
4
5
6
7
 Do you want to continue?(y/n)n
*/
