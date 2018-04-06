/*Imagine a publishing company which does marketing for book and audiocassette versions. 
Create a class publication that stores the title (a string) and price (type float) of a publication. 
From this class derive two classes: book, which adds a page count (type int), and tape, which 
adds a playing time in minutes (type float). 
Write a program that instantiates the book and tape classes, allows user to enter data and 
displays the data members. If an exception is caught, replace all the data member values with 
zero values. */

#include<iostream>
using namespace std;

class publication
{
protected:
string title;
float price;
};

class book: public publication
{
int page_count;
public:
void get()
{
cout<<"Enter title, price and page count: ";
cin>>title>>price>>page_count;
try
{
if(page_count<0)
throw 1;
}
catch(int i)
{
if(i==1)
{
cout<<"Invalid page count";
page_count=0;
}
}
}

void print()
{
cout<<"\n Title: "<<title<<"\n Price: "<<price<<"\n Page count: "<<page_count;
}
};

class tape: public publication
{
float time;
public:
void get()
{
cout<<"\n Enter title, price and playing time: ";
cin>>title>>price>>time;
try
{
if(time<0)
throw 1;
}
catch(int i)
{
if(i==1)
{
cout<<"Invalid playing time";
time=0;
}
}
}

void print()
{
cout<<"\n Title: "<<title<<"\n Price: "<<price<<"\n Playing time: "<<time;
}
};

int main()
{
book obj1;
obj1.get();
obj1.print();
tape obj2;
obj2.get();
obj2.print();
return 0;
}


