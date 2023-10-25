#include<iostream>
using namespace std;

class time1
{
    int hrs;
    int mins;

public:
    time1(){}
    time1(int t)
    {
        hrs=t/60;
        mins=t%60;
    }

    void display()
    {
        cout<<hrs<<"hrs"<<mins<< " mins";
    }
};

int main()
{
    time1 t1;
    int duration=105;
    t1=duration;
    t1.display();
}