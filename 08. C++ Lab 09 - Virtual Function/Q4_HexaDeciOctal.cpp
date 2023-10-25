#include<iostream>

using namespace std;

class Base
{
    protected:
        int val;
    public:
        virtual void set_val()=0;
        virtual void display()=0;
};

class Octal: public Base
{
    public:
        void set_val()
        {
            cout<<"\nEnter a decimal value: ";
            cin>>val;

        }
        void display()
        {
            cout<<"Octal value: "<<oct<<val;
        }
};

class Hexa: public Base
{
    public:
        void set_val()
        {
            cout<<"\nEnter a decimal value: ";
            cin>>val;
        }
        void display()
        {
            cout<<endl<<"Hexadecimal Value: "<<hex<<val;
        }
};

class Decimal1: public Base
{
    public:
        void set_val()
        {
            cout<<"\nEnter a decimal value: ";
            cin>>val;

        }
        void display()
        {
            cout<<endl<<val;
        }
};

int main()
{
    Octal oct;
    Hexa hexa;
    Decimal1 d;
    Base *b[]={&oct,&hexa,&d};

    for(int i=0;i<3;i++)
    {
        b[i]->set_val();
        b[i]->display();
    }
}

