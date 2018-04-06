/*Create employee bio
-
data using following classes i) Personal record ii))Professional record iii) 
Academic record Assume appropriate
data members and member function to accept required 
data & print bio
-
data. Create bio
-
data using multiple inheritance using C++. */

#include<iostream>
using namespace std;

class personal
{
protected:
string name,email;
long int mobile;
};

class professional
{
protected:
int emp_id;
string company;
};

class academic
{
protected:
int passing;
float percent;
string qualification;
};

class biodata: public personal,public professional,public academic
{
public:
void get()
{
cout<<"Enter name:";
cin>>name;
cout<<"Enter email:";
cin>>email;
cout<<"Enter mobile:";
cin>>mobile;
cout<<"Enter passing year";
cin>>passing;
cout<<"Enter qualification:";
cin>>qualification;
cout<<"Enter percentage:";
cin>>percent;
cout<<"Enter company name and employee id:";
cin>>company>>emp_id;
}

void print()
{
cout<<"\n Name:"<<name<<"\n Email"<<email<<"\n Mobile"<<mobile<<"\n Passing year:"<<passing<<"\n Qualification"<<qualification<<"\n percentage"<<percent<<"\n company name:"<<company<<"\n Employee id"<<emp_id;
}
};

int main()
{
biodata obj;
obj.get();
obj.print();
return 0;
}

