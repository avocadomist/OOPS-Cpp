#include <iostream>
using namespace std;

class dist2;
class dist1
{
    int f, i;

public:
    void input()
    {
        cout << "Enter distance in feet & inches : ";
        cin >> f>>i;
    }
    
	friend void compare(dist1 , dist2);
};

class dist2
{
    int m, c;

public:
    void input()
    {
        cout << "Enter distance in meters & centimeters: ";
        cin >> m>>c;
    }
    
    friend void compare(dist1 , dist2);
};

void compare(dist1 p, dist2 q)
{
    double d1, d2;
    d1 = p.f * 30.48 + p.i * 2.54;
    d2 = q.m * 100 + q.c;
    
    if (d1 > d2)
    cout << "Distance 1 is greater than Distance 2." << endl;
    
    else if (d1 == d2)
    cout << "Distance 1 is equal to Distance 2." << endl;
    
    else
    cout << "Distance 1 is lesser than Distance 2." << endl;
    
}

int main()
{
    dist1 p;
    dist2 q;
    cout << "Enter distance 1 in feet & inches " << endl;
    p.input();
    cout << "Enter distance 1 in meters & centimeters " << endl;
    q.input();
    
    compare(p, q);
    
    return 0;
}


