#include <iostream>

using namespace std;
class student
{
	protected:
	string name;
	int roll;
	int age;
	public:
		student(string n,int r,int a)
		{
			name=n;
			roll=r;
			age=a;
		}
};
class test:virtual public student
{
    protected:
	int m[3];
	public:
		test(string n,int r,int a,int m1,int m2,int m3):student(n,r,a)
		{
			m[0]=m1;
			m[1]=m2;
			m[2]=m3;
		}
		int test_tot()
		{
			return (m[0]+m[1]+m[2]);
		}
};
class activity:virtual public student
{
	int act[2];
	public:
		activity(string n,int r,int a,int a1,int a2):student(n,r,a)
		{
			
			act[0]=a1;
			act[1]=a2;
		}
		int act_tot()
		{
			return (act[0]+act[1]);
		}
};
class result:public test,public activity
{
	public:
		result(string n,int r,int a,int m1,int m2,int m3,int a1,int a2):student(n,r,a),test(n,r,a,m1,m2,m3),activity(n,r,a,a1,a2)
		{
		int t=test_tot()+act_tot();
		cout<<"name:"<<name<<endl;
		cout<<"roll:"<<roll<<endl;
		cout<<"age:"<<age<<endl;	
		cout<<"total score is\n"<<t;
		cout<<"percentage:\n"<<(t/5);
		if(t>=400 & t<=500)
		{
		   cout<<"grade A\n";
		}
		else if(t>=300 & t<=399)
		{
		   cout<<"grade B\n";
		}
		else if(t>=200 & t<=299)
		{
		   cout<<"grade C\n";
		}
	}
};
int main()
{
	result r("Sud",574,19,45,56,89,77,99);
}