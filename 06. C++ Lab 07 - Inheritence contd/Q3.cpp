#include<iostream>
#include<string.h>
using namespace std;

class student
{
	protected:
	int roll;
	string name;
	
	public:
	student(int r, string n)
	{
		cout<<"\nStudent constructor called...\n";
		roll=r;
		strcpy(name,n);
	}
	
	void s_display()
	{
		cout<<"\nRoll no. : "<<roll;
		cout<<"\nName : "<<name<<endl;
	}	
};

class tests : virtual public student
{
	protected:
	int m[3];
	
	public:
	tests (int r, string n, int m1, int m2, int m3) : student(r,n)
	{
		m[0]=m1;
		m[1]=m2;
		m[3]=m3;
		cout<<"\nTest constructor called...\n";
	}
	
	int total_t()
	{
		return(m[0]+m[1]+m[2]);
	}
};

class activities : virtual public student
{
	protected:
	int a[2];
	
	public:
	activities (int r, string n, int a1, int a2) : student(r,n)
	{
		a[0]=a1;
		a[1]=a2;
	}
	
    int total_a()
	{
		return(a[0]+a[1]);
	}
};

class result: public tests, public activities
{
	public: 
	result(int r, string n, int m1, int m2, int m3, int a1, int a2) : student(r,n), tests(r,n,m1,m2,m3), activities(r,n,a1,a2)
	{
		cout<<"\nResult constructor called...\n";
	}
	
	void total()
	{
		cout<<"\nTotal = "<<total_t()+total_a();
	}
};















