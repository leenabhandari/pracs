#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *lc,*rc;
    node()
    {
        data=0;
        lc=NULL;
        rc=NULL;
    }
};

class op
{
public:
    node *temp,*root;
    int number,flg;
    op()
    {
        temp=NULL;
        root=NULL;
    }

    void create()
    {
        int num;
        char c;
        temp=new node;
        root=temp;
        number=1;
        up:
        cout<<"Enter number: ";
        cin>>num;
        if(temp->data==0)
            temp->data=num;
        else insert(num,temp);
        cout<<"Do you wish to continue: ";
        cin>>c;
        if(c=='y')
        {
            number++;
            goto up;
        }
    }

    void insert(int num,node *r)
    {
        node *cur;
        cur=new node;
        cur->data = num;
        if(num<r->data)
        {
            if(r->lc==NULL)
                r->lc=cur;
            else insert(num,r->lc);
        }
        else
        {
            if(r->rc==NULL)
                r->rc=cur;
            else insert(num,r->rc);
        }
    }

    void inorder(node *r)
    {
       if(r!=NULL)
        {
            inorder(r->lc);
            cout<<r->data<<"\t";
            inorder(r->rc);
        }
    }

     void mirror(node *r)
    {
        if(r!=NULL)
        {
            mirror(r->rc);
            cout<<r->data<<"\t";
            mirror(r->lc);
        }
    }

    void modify(node *r,int ser,int new1)
    {
        if(r!=NULL)
        {
            modify(r->rc,ser,new1);
            if(ser==r->data)
                r->data=new1;
            modify(r->rc,ser,new1);
        }
    }
    void small(node *r)
    {
        while(r->lc!=NULL)
            r=r->lc;
        cout<<"\nSmallest number: "<<r->data;
    }

    void search(node *r, int n,int com)
    {
        if(n==r->data)
        {
            com++;
            flg=1;
            cout<<"\n Search successful! Number of comparisons: "<<com;
        }
        else if(n<r->data)
        {
            if(r->lc!=NULL)
            {
            com++;
            search(r->lc,n,com);
            }
        }
        else if(n>r->data)
        {
            if(r->rc!=NULL)
            {
            com++;
            search(r->rc,n,com);
            }
        }
    }

    node* del(node *r,int n)
    {
        node *d;
        if(n>r->data)
            r->rc=del(r->rc,n);
        else if(n<r->data)
            r->lc=del(r->lc,n);
        else if(n==r->data)
        {
            if(r->lc==NULL && r->rc==NULL)
            {
                delete r;
                r=NULL;
            }
            else if(r->lc==NULL)
                r=r->rc;
            else if(r->rc==NULL)
                r=r->lc;
            else{
                d=r->rc;
                while(d->lc!=NULL)
                    d=d->lc;
                r->data=d->data;
                r->rc=del(r->rc,d->data);
            }
        }
        return r;
    }

};

int main()
{
    op o;
    node *r;
    int no,ser,new1;
    o.create();
    o.inorder(o.root);
    cout<<"Enter number to be deleted: ";
    cin>>ser;
    r=o.del(o.root,ser);
    //cout<<"Enter new number: ";
    //cin>>new1;
    //o.modify(o.root,ser,new1);
    cout<<endl;
    o.inorder(o.root);
   // o.mirror(o.root);
      //  o.small(o.root);
    //cout<<"\nEnter number to be searched: ";
    //cin>>no;
    //o.search(o.root,no,0);
    //if(o.flg!=1) cout<<"Search not successful";
    return 0;
}
