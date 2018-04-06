#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

class conv
{
char exp[50],c,ans[50];
int i,n,k=0;
stack<char> s;
public:
void enter()
{
cout<<"Enter the expression: ";
cin>>exp;
n=strlen(exp);
for(i=0;i<n;i++)
	{
	c=exp[i];
	switch (c)
	{
		case '/':
		case '*':
		{
		s.push(c);
		break;
		}
		case '+':
		case '-':
		{
		while(!s.empty())
		{
		ans[k++]=s.top();
		s.pop();
		}
		s.push(c);
		break;
		}
		default:
		{
		ans[k++]=c;
		}
	}
	

}
while(!s.empty())
{
ans[k++]=s.top();
s.pop();
}
for(i=0;i<n;i++)
cout<<ans[i]<<endl;
}
};

int main()
{
conv o;
o.enter();
return 0;
}
