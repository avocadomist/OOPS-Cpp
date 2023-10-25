#include <iostream>
using namespace std;

class dist{
    int f,i;
    public:
    dist(int a=0,int b=0){
        f=a;i=b;
    }
    void display(){
        cout<<f<<" feet "<<i<<" inches"<<endl;
    }
    dist operator +(dist d){
        dist t;
        t.i=i+d.i;
        t.f=f+d.f+(t.i/12);
        t.i=t.i%12;
        return t;
    }
};

int main()
{
    dist d1(10,5),d2(4,6),d3,d4;
    d3=d1+d2; 
    d4=d1.operator +(d2);
    d3.display();
    d4.display();

}
