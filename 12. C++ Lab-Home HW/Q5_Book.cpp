#include<iostream>
#include<fstream>

using namespace std;

class Book
{
    int Bno;
    char Title[30];
    public : 
        int RBno()
        {
            return Bno;
        }
        void Enter()
        {
            cout<<"Enter Book no.: ";
            cin>>Bno;
            cout<<"Enter book title: ";
            fflush(stdin);
            gets(Title);
        }
        void Display()
        {
            cout<<"\n"<<"Book No.: "<<Bno<<" Title: "<<Title<<endl;
        }
};

int main()
{
    int n,pos,c=0;
    cout<<"Enter number of books: ";
    cin>>n;
    Book b1[n],b2[n];
    fstream f1;
    f1.open("BOOK.dat",ios::out | ios::binary);
    
    for(int i=0;i<n;i++)
    {
    	cout<<"Book "<<i+1<<endl;
        b1[i].Enter();
        f1.write((char*)&b1[i], sizeof(b1[i]));
    }

    f1.close();

    f1.open("BOOK.dat",ios::in | ios::binary);
    cout<<"Enter Book No. to search: ";
    cin>>pos;
    for(int i=0;i<n;i++)
    {
    	f1.read((char*)&b2[i], sizeof(b2[i]));
        if(pos==b2[i].RBno())
            {b2[i].Display();c++;}
    }
    f1.close();

    if(c==0)
        cout<<"\nBook not found";
}