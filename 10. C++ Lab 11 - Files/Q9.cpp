//9
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char name[20],n[20];
    int age,a;
   
    ofstream o("Human.txt");
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter age: ";
    cin>>age;
    
    o<<name<<"\n";
    o<<age<<"\n";
    
    o.close();
    ifstream i;
    i.open("Human.txt");
    i>>n;
    cout<<"Name: "<<n<<endl;
    i>>a;
    cout<<"Age: "<<a<<endl;
    
}