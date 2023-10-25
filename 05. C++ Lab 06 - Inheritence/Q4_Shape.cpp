#include <iostream>
using namespace std;

class shape
{
	public:
		virtual void get();
		virtual void area();	
};

class circle:public shape
{
	float r;
	public:
		void get()
		{
			cout<<"\nenter radius: ";
			cin>>r;
		}
		void area()
		{
			cout<<"\narea of circle: "<<(3.14*r*r)<<endl;
		}
};

class square:public shape
{
	int s;
	public:
		void get()
		{
			cout<<"\nenter side: ";
			cin>>s;
		}
		void area()
		{
			cout<<"area of square: "<<s*s<<endl;
		}
};

class triangle:public shape
{
	int h,b;
	float a;
	public:	
	
	    void get()
	    {
	    	cout<<"\nenter height: ";
	    	cin>>h;
			cout<<"enter base: ";
			cin>>b;
		}
		
	    void area()
	    {
			a=0.5*h*b;
			cout<<"\narea of triangle: "<<a<<endl;
		}
};

int main()
{
	circle cr;
	square sq;
	triangle tri;
	
	shape* p[3];
	p[0]=&cr;
	p[1]=&sq;
	p[2]=&tri;
	
	for (int i=0; i<3; i++)
	{
		p[i]->get();
		p[i]->area();
	}
	return 0;
}


