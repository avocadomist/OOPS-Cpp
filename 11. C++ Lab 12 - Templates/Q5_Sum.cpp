#include <iostream>
using namespace std;

template<class T1,class T2>

void sum(T1 a,T2 b) 
{
    cout<<"Sum="<<a+b<<endl;
}

int main()
{
    int a,b;
    float x,y;
    cout<<"Enter 2 integers: ";
    cin>>a>>b;
    cout<<"Enter 2 float nos.: ";
    cin>>x>>y;
    
    sum(a,b); 
    sum(x,y); 
    sum(a,y); 
    
    return 0;
}