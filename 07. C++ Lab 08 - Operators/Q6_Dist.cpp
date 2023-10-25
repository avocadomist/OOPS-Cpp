#include<iostream>
using namespace std;

class dist
{
    int f,i;
    
    public:
    dist(int a=0, int b=0)
	{
        f=a;
        i=b;
    }
    
    void display()
	{
        cout<<f<<" feet "<<i<<" inches";
    }
    
    dist operator +(dist d){
        dist t;
        t.i= d.i + i;
        t.f= d.f + f+ (t.i/12);
        t.i= t.i % 12;
        return t;
    }
    dist operator >(dist d){
        dist d1, d2;
        d1.f=f+i/12;
        d1.i=i%12;
        d2.f=d.f+d.i/12;
        d2.i=d.i%12;
        if(d1.f>d2.f && d1.i>d2.i)
        return *this;
        else
        return d;
    }
    bool operator ==(dist d){
        f=f+i/12;
        i=i%12;
        d.f=d.f+d.i/12;
        d.i=d.i%12;
        if(f==d.f && i==d.i){
            return true;
        }
        else
            return false;
    }
};

int main(){
    dist d1, d2(8,7), d3(9,13),d4;
    d1=d2+d3;
    cout<<"S.um is: ";
    d1.display();
    bool b;
    b=d2==d3;
    if(b==1)
    cout<<"Distances are equal\n";
    else 
    cout<<"\nDistances are not equal\n";
    d4=d2>d3;
    cout<<"The greater distance is: ";
    d4.display();
    return 0;
}