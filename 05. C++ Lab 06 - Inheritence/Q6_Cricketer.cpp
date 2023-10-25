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
    void getdata()
    {
        cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter age: ";
		cin>>age;
		cout<<"Enter jersey no.: ";
		cin>>jno;
		cout<<"Enter no. of ODIs played: ";
		cin>>nodi;
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
    void getdata()
    {
    	cricketer::getdata();
        cout<<"Enter runs: ";
		cin>>run;
		cout<<"Enter batting avg: ";
		cin>>bavg;
		cout<<"Enter no. of half centuries: ";
		cin>>nhc;
		cout<<"Enter no. of centuries: ";
		cin>>nc;
		cout<<"Enter strike rate: ";
		cin>>sr;
		cout<<"Enter highest score: ";
		cin>>hs;
		cout<<"Enter no. of sixes: ";
		cin>>ns;
		cout<<"Enter no. of six longest: ";
		cin>>nls;
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
    void getdata()
    {
        cricketer::getdata();
        cout<<"Enter type: ";
		cin>>ty;
		cout<<"Enter wicket taken: ";
		cin>>nw;
		cout<<"Enter runrate: ";
		cin>>rr;
		cout<<"Enter speed: ";
		cin>>s;
		cout<<"Enter economy: ";
		cin>>ec;
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
	batsman bt;
	baller bl;
	
	cout<<"Batsman details: \n";
	bt.getdata();
	bt.display();
	
	cout<<"\n\nBaller details: \n";
	bl.getdata();
	bl.display();
	
	return 0;
}