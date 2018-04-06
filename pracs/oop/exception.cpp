//Crete User defined exception to check the following conditions and throw the exception if the criterion does not meet.
//  a. User has age between 18 and 55
//  b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
//  c. User stays in Pune/ Mumbai/ Bangalore / Chennai
//  d. User has 4-wheeler Accept age, Income, City, Vehicle from the user
//  and check for the conditions mentioned above. If any of the condition not met then throw the exception
#include <iostream>


using namespace std;
class user
{
    int cchoice, age, sal, vchoice;
public:
    void get()
    {
    cout<<"\n Welcome!\n";
go: try{
    cout<<"\nEnter age ";
    cin>>age;
    if(age<18||age>55)
        throw age;

    cout<<"\nEnter salary ";
    cin>>sal;
    if(sal<50000||sal>100000)
        throw sal;

    cout<<"\nLocation:";
    cout<<"\nEnter 1 for Pune \n2 for Mumbai \n3 for Bangalore \n4 for Chennai \n5 if you stay in any other city ";
    cin>>cchoice;
     if(cchoice==5)
    throw cchoice;

    cout<<"\nEnter 1 for 2 wheeler";
    cout<<"\nEnter 2 for 4 wheeler";
    cout<<"\nEnter 3 if you drive anything else";
    cin>>vchoice;
     if(vchoice==3)
    throw vchoice;

    cout<<"\n Thank you for your time";
        }
      catch(int a)
  {
      cout<<"\n invalid entry "<<a<<"\n please try again";
      goto go;
  }
  }


};

int main()
{
    user u;
    u.get();
    return 0;
}

/* Welcome!

Enter age 18

Enter salary 0

 invalid entry 0
 please try again
Enter age 18

Enter salary 2400000

 invalid entry 2400000
 please try again
Enter age 18

Enter salary 60000

Location:
Enter 1 for Pune 
2 for Mumbai 
3 for Bangalore 
4 for Chennai 
5 if you stay in any other city 1

Enter 1 for 2 wheeler
Enter 2 for 4 wheeler
Enter 3 if you drive anything else1

 Thank you for your time */
