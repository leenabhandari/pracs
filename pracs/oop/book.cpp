/*A book shop maintains the inventory of books that are being sold at the shop. The list includes
details such as author, title, price, publisher and stock position. Whenever a customer wants a
book, the sales person inputs the title and author and the system searches the list and displays
whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the
system displays the book details and requests for the number of copies required. If the
requested copies book details and requests for the number of copies required. If the requested
copies are available, the total cost of the requested copies is displayed; otherwise the message
―
Required copies not in stock‖ is displayed. Design a system using a class called books with
suitable member functions and Constructors. Use new operator in constructors to allocate
memory space required. Implement C++ program for the system.
*/

#include<iostream>
#include<string.h>
using namespace std;

class Book
{
public:
string author,title,publisher;
int stock;
float price;

void get()
{
cout<<"Enter author,title,publisher,price and stock";
cin>>author>>title>>publisher>>price>>stock;
}

void show()
{
cout<<"The details are"<<endl;
cout<<"Author:"<<author<<endl<<"Title:"<<title<<endl<<"Publisher:"<<publisher<<endl<<"Stock"<<stock<<endl<<"Price:"<<price;
}

};

int main()
{
int n,s,c,x=1;
float p,tot;
string t,a;
Book b[50];
cout<<"Enter number of books:";
cin>>n;

for(int i=0;i<n;i++)
{
b[i].get();
}

for(int i=0;i<n;i++)
{
b[i].show();
}

cout<<endl<<"Enter the book details(author and title): ";
cin>>a>>t;

for(int i=0;i<n;i++)
if(t==b[i].title && a==b[i].author )
{
cout<<"Book found. Details are:"<<endl;
cout<<"Author:"<<b[i].author<<endl<<"Title:"<<b[i].title<<endl<<"Publisher:"<<b[i].publisher<<endl<<"Stock:"<<b[i].stock<<endl<<"price:"<<b[i].price;
s=b[i].stock;
p=b[i].price;
x=0;
cout<<endl<<"Enter number of copies";
cin>>c;
if(c<=s)
{
tot=c*p;
cout<<"Total price="<<tot;
}
else cout<<"Required copies not in stock";
}

if(x!=0)
cout<<"Book not found";

return 0;
}







