#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
void create();
void deposit();
void withdraw();

struct bank
{
    int acno;
    char name[50];
    float balance;
}account[100];

int i=0;
int lb_accno=1000,ub_accno=9999;

int main()
{
    int choice;
    restart:
        cout<<"\n\tBanking Program\n";
        cout<<endl<<"1. Create a New Account";
        cout<<endl<<"2. Cash Deposit";
        cout<<endl<<"3. Cash Withdraw";
        cout<<endl<<"4. Exit";
        cout<<endl<<"Enter the Choice : ";
            cin>>choice;

    switch (choice)
    {
        case 1:
            create();
            goto restart;

        case 2:
            deposit();
            goto restart;

        case 3:
            withdraw();
            goto restart;

        case 4:
            exit(0);

        default:
            cout<<endl<<"Invalid Choice!"<<endl<<endl;
            Sleep(2);
            goto restart;
    }
}

void create()
{
    cout<<endl<<"\tNEW ACCOUNT CREATION"<<endl;
    int j;
    j=(rand()%(ub_accno-lb_accno+1))+lb_accno;
    cout<<"Your Account Number is : "<<j;
    account[i].acno=j;

    cout<<endl<<"Enter Your Name :\t";
    cin>>account[i].name;
    cout<<"The Minimum Deposit is Rs.500"<<endl;
    cout<<"Rs.500 has been Deposited !"<<endl;
    account[i].balance=500;
    i++;
    Sleep(5);
}

void deposit()
{
    int acc,b,m=0;
    float dep_amt;
    cout<<endl<<"\tCASH DEPOSIT"<<endl;
    cout<<"Enter Your Account Number : \t";
    cin>>acc;

    for(b=0;b<i;b++)
    {
        if(account[b].acno==acc)
            m=b;
    }

    if(account[m].acno==acc)
    {
        cout<<endl<<"Account Number : ",account[m].acno;
        cout<<endl<<"Name : ",account[m].name;
        cout<<endl<<"Current Balance : ",account[m].balance;
        cout<<endl<<endl<<"Enter the Amount to Deposit : ";
            cin>>dep_amt;
        account[m].balance = account[m].balance + dep_amt;
        cout<<endl<<"Rs."<<dep_amt<<" Successfully Deposited !";
        cout<<endl<<endl<<"Account Balance After Deposit : "<<account[m].balance;
        Sleep(5);
    }
    else
    {
        cout<<"The Account Number is Invalid ! ";
        Sleep(5);
    }
}


void withdraw()
{
    int acc,b,m=0;
    float wit_amt;
    cout<<endl<<"\tCASH WITHDRAWAL";
    cout<<endl<<"Enter Your Account Number :\t";
    cin>>acc;

    for(b=0;b<i;b++)
    {
        if(account[b].acno==acc)
            m=b;
    }

    if(account[m].acno==acc)
    {
        cout<<endl<<"Account Number : ",account[m].acno;
        cout<<endl<<"Name : ",account[m].name;
        cout<<endl<<"Current Balance : ",account[m].balance;
        cout<<endl<<endl<<"Enter the Amount to Withdraw : ";
            cin>>wit_amt;

        if(account[m].balance<wit_amt+500)
        {
            cout<<"Minimum Account Balance Must Be Rs.500"<<endl;
            cout<<endl<<"Insufficient Funds! Transaction Declined";
            Sleep(5);
        }
        else
        {
            account[m].balance= account[m].balance - wit_amt;
            cout<<endl<<"Rs."<<wit_amt<<"Successfully Withdrawn !";
            cout<<endl<<endl<<"Account Balance After Withdrawal : "<<account[m].balance;
        }
    }
    else
    {
        cout<<endl<<"The Account Number is Invalid !";
        Sleep(5);
    }
}
