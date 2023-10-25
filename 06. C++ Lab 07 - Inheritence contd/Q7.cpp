#include <iostream>
using namespace std;

class batsman
{
	protected:
    int rt, bavg, nhc, nc;
    float sr;

public:
    batsman(int r, int b, int nh, int n, float s)
    {
        rt = r;
        bavg = b;
        nhc = nh;
        sr = s;
    }
    void display()
    {
        cout << rt << endl;
        cout << bavg << endl;
        cout << nhc << endl;
        cout << sr << endl;
    }
};

class baller
{
	protected:
    char tp[10];
    int nh;
    float rr, sp;

public:
    baller(char t[], int n, float r, float s)
    {
        for (int i = 0; i < 10; i++)
        {
            tp[i] = t[i];
        }
        nh = n;
        rr = r;
        sp = s;
    }
    void display()
    {
        cout << tp << endl;
        cout << nh << endl;
        cout << rr << endl;
        cout << sp << endl;
    }
};

class allrounder : public batsman, public baller
{
    int nm, imp, nc, rnk, nst;

public:
    allrounder(int n, int i, int ncc, int r, int ns) : batsman(int r, int b, int nh, int n, float s), baller(char t[], int n, float r, float s)
    {
        nm = n;
        imp = i;
        nc = ncc;
        rnk = r;
        nst = ns;
    }
    
    void display()
    {
        cout << nm << endl;
        cout << imp << endl;
        cout << nc << endl;
        cout << rnk << endl;
        cout << nst << endl;
    }
};

int main()
{
	allrounder A;
	A.batsman :: getdata();
	A.baller :: getdata();
	A.getdata();
	A.batsman :: display();
	A.baller :: display();
	A.display();
}






