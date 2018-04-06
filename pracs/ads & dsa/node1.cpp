/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node is reserved for secretary of club. Write C++ program to maintain club members
information using singly linked list. Store student PRN and Name. Write functions to a) Add and 
delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists. */


#include<iostream>
using namespace std;

class node
{
	public:
	string name;
	int prn;
	node *next;
};

class op
{
public:

char c,m;
	node *temp,*head,*last,*temp1,*head1,*last1;
	int pos;
	int coun;
void create()
{

	cout<<"Enter the details:";
	temp=new node;
	head=temp;
	x:
	cout<<"Enter name:";
	cin>>temp->name;
	cout<<"Enter PRN:";
	cin>>temp->prn;
	temp->next=new node;
	temp=temp->next;
	cout<<"Do you want to add a member?(y/n)";
	cin>>c;
	if (c=='y')
	goto x;
	last=temp;
	temp->next=NULL;
	}
	
	void display()
	{
	cout<<"Entered details are:";
	temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->name<<temp->prn<<endl;
	    temp=temp->next;
		
	}
	}
	
	void count()
	{
	temp=head;
	coun=0;
	while(temp->next!=NULL)
	{
		coun++;
		temp=temp->next;
	}
	cout<<"Total members are:"<<coun;
	int t=1;
	}
	
	
	void add()
	{
		int t=1,pos;
			cout<<"Enter the position at which you wish to enter:";
		cin>>pos;
		temp=head;
		
		if(pos==1)
		{
			node *ptr1;
			ptr1=new node;
			cout<<"Enter name:";
			cin>>ptr1->name;
			cout<<"Enter prn:";
			cin>>ptr1->prn;
			ptr1->next=temp;
			head=ptr1;
		}
		else if(pos==coun)
		{
			temp=last;
			node *temp2;
			temp2=new node;
			cout<<"Enter name:";
		cin>>temp2->name;
		cout<<"Enter prn:";
		cin>>temp2->prn;
		temp2->next=NULL;
			temp->next=temp2;
			
			
		last=temp2;
				
		}
		
		
		else
		{
		
		while(t!=pos-1)
		{
			temp=temp->next;
			t++;
			
		}
		node *ptr;
		ptr=temp->next;
		temp->next=new node;
		temp=temp->next;
		cout<<"Enter name:";
		cin>>temp->name;
		cout<<"Enter prn:";
		cin>>temp->prn;
		temp->next=ptr;
		}
	}
		
void dele()
	{
		int posi,mn=1;
		cout<<"Enter element position you wish to delete:";
		cin>>posi;
		temp=head;
		if(posi==1)
		{
			head=temp->next;
			delete temp;
		
		}
		else if(posi==coun)
		{
		while(mn!=coun)
			{
				temp=temp->next;
				mn++;
				
			}
			
			temp->next=NULL;
			last=temp;
			delete temp->next;
		}
		else
		{
			temp=head;
			node *temp2;
			temp2=head;
			while(mn!=posi)
			{
				
				temp=temp->next;
				mn++;
				
			}
			
			while(temp2->next!=temp)
			{
				temp2=temp2->next;
			}
			temp2->next=temp->next;
			temp->next=NULL;
			
			delete temp->next;
			
		
		}
	}
	
	void create1()
{

	cout<<"Enter the details:";
	temp1=new node;
	head1=temp1;
	x:
	cout<<"Enter name:";
	cin>>temp1->name;
	cout<<"Enter PRN:";
	cin>>temp1->prn;
	temp1->next=new node;
	temp1=temp1->next;
	cout<<"Do you want to add a member?(y/n)";
	cin>>c;
	if (c=='y')
	goto x;
	last1=temp1;
	temp1->next=NULL;
	}
	
	
	void concat()
	{
	temp=head;
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp=temp->next;
	temp->next=head1;
	}
	
	
	
	};
	
	
	int main()
	{
	int cho;
	op o;
	o.create();
	o.display();
	o.count();
	cout<<"Enter \n 1 for adding \n 2 for deleting \n 3 for concatenation:";
	cin>>cho;
	if(cho==1)
	{
	o.add();
	o.display();
	}
	else if(cho==2)
	{
	o.dele();
	o.display();
	}
	else if(cho==3)
	{
	o.create1();
	o.concat();
	o.display();
	}
	else cout<<"Invalid operation.";
	
	
	
	
	return 0;
	}
	
	
