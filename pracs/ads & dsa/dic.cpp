//============================================================================
// Name        : dic.cpp
// Author      : lm
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;


class node
{
	public:
	       char name[50];
	       node *lc,*rc;
	       string mean;
};

class tree
{
public:
	node *root;
	tree()
	{
		root=NULL;
	}
	void create()
	{
		char c;
		xyz:
		node *temp;
		temp=new node;

		cout<<"Enter val:";
		cin>>temp->name;
		cout<<"Enter meaning: ";
		cin>>temp->mean;
		temp->lc=NULL;
		temp->rc=NULL;

		if(root==NULL)
			root=temp;
		else insert(temp,root);

		cout<<"Do you wish to continue: ";
		cin>>c;
		if(c=='y')
			goto xyz;


	}

	void insert(node *t,node *root)
	{

		for(int i=0;i<strlen(t->name);i++)
		{
			if(t->name[i]==root->name[i])
				continue;

			if(t->name[i]>root->name[i])
			{
				if(root->rc==NULL)
					root->rc=t;
				else insert(t,root->rc);
				break;
			}
			if(t->name[i]<root->name[i])
					{
						if(root->lc==NULL)
							root->lc=t;
						else insert(t,root->lc);
						break;
					}
		}

	}

	void inorder(node *root)
	{
		node *t;
		t=root;
		if(t!=NULL)
		{
		inorder(root->lc);
		cout<<endl<<root->name<<" ";
		inorder(root->rc);
		}
	}

	void preorder(node *root)
		{
			node *t;
			t=root;
			if(t!=NULL)
			{
				cout<<endl<<root->name<<" ";
			preorder(root->lc);

			preorder(root->rc);
			}
		}

	void postorder(node *root)
			{
				node *t;
				t=root;
				if(t!=NULL)
				{

				preorder(root->lc);

				preorder(root->rc);
				cout<<endl<<root->name<<" ";
				}
			}

	void smallest(node *root)
	{
		if(root->lc==NULL)
			cout<<"Smallest is: "<<root->name;
		else smallest(root->lc);
	}

	void largest(node *root)
		{
			if(root->rc==NULL)
				cout<<"largest is: "<<root->name;
			else largest(root->rc);
		}

	void search(node *root,string key)
	{
		int flag=0;
		if(root->name==key)
		{
			cout<<"Found";
			flag=1;
		}
		else if(flag==0)
			cout<<"Not found";
		else
		{
			if(key.compare(root->name)<0)
				search(root->lc,key);
			else if(key.compare(root->name)>0)
				search(root->rc,key);

		}


	}
};
int main() {
	cout << "" << endl; // prints 
	tree o;
	char key[50];
	o.create();
	o.inorder(o.root);
	o.preorder(o.root);
	o.postorder(o.root);
	o.smallest(o.root);
	o.largest(o.root);
	cout<<"Enter key: ";
	cin>>key;
	o.search(o.root,key);
	return 0;
}
