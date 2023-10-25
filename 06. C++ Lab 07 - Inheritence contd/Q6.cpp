#include <iostream>
using namespace std;

class cricketer
{
protected:
    string name;
    int age;
    int jno;
    int nodi;

public:
    cricketer(string n, int a, int j, int o)
    {
    	name=n;
    	age=a;
    	jno=j;
    	nodi=o;
	}
    
    void display()
    {
    	cout<<"\nName: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"jersey no.: "<<jno<<endl;
		cout<<"No. of ODIs played: "<<nodi<<endl;
	}
};

class batsman : public cricketer
{
    int run, bavg, nhc, nc, sr, hs, ns, nls;

public:
    batsman(string n, int a, int j, int o, int r, int b, int nhc1, int nc1, int sr1, int hs1, int ns1, int nls1):cricketer(n,a,j,o)
    {
    	run=r;
    	bavg=b;
    	nhc=nhc1;
    	nc=nc1;
    	sr=sr1;
    	hs=hs1;
    	ns=ns1;
    	nls=nls1;
	}
    
    void display()
    {
    	cricketer::display();
    	cout<<"Runs: "<<run<<endl;
		cout<<"Batting avg: "<<bavg<<endl;
		cout<<"No. of half centuries: "<<nhc<<endl;
		cout<<"No. of centuries: "<<nc<<endl;
		cout<<"Strike rate: "<<sr<<endl;
		cout<<"Highest score: "<<hs<<endl;
		cout<<"No. of sixes: "<<ns<<endl;
		cout<<"No. of six longest: "<<nls<<endl;
	}
};

class baller : public cricketer
{
    string ty;
    int nw, s, ec;
    float rr;

public:
    baller(string n, int a, int j, int o, string t, int nw1, int s1, int e, float rr1):cricketer(n,a,j,o)
    {
    	ty=t;
    	nw=nw1;
    	s=s1;
    	ec=e;
    	rr=rr1;
	}
    
    void display()
    {
        cricketer::display();
    	cout<<"Type: "<<ty<<endl;
		cout<<"Wicket taken: "<<nw<<endl;
		cout<<"Runrate: "<<rr<<endl;
		cout<<"Speed: "<<s<<endl;
		cout<<"Economy: "<<ec<<endl;
    }
};

int main()
{
	batsman bt("Vir", 33, 18, 262, 12344, 58, 64, 43, 160, 183, 125, 2);
	baller bl("Div", 32, 17, 260, "right-arm", 4, 152, 7, 93.4);
	
	cout<<"Batsman details: \n";
	bt.display();
	
	cout<<"\n\nBaller details: \n";
	bl.display();
	
	return 0;
}