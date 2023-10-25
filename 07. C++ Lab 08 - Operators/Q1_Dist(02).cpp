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
    friend dist operator +(int,dist);
};
dist operator +(int a,dist d){
    dist t;
    t.i=a+d.i;
    t.f=d.f+(t.i/12);
    t.i=t.i%12;
    return t;
}

int main()
{
    dist d2(4,6),d3;
    d3=7+d2;
    d2.display();
    d3.display();

}
