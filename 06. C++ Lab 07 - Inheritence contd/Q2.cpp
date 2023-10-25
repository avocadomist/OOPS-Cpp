#include <iostream>
using namespace std;
class student
{
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
		void display()
		{
			cout<<"\nname:"<<name<<endl;
			cout<<"roll:"<<roll<<endl;
			cout<<"age:"<<age<<endl;
		}
};
class test:public student
{
	protected:
	int marks[5];
	public:
		test(string n,int r,int a,int m1,int m2,int m3,int m4,int m5):student(n,r,a)
		{
		    marks[0]=m1;
		    marks[1]=m2;
		    marks[2]=m3;
		    marks[3]=m4;
		    marks[4]=m5;
		}
		void display()
		{
		    student::display();
		    cout<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<" "<<marks[3]<<" "<<marks[4];
		}
};
class result:public test
{
	public:
		result(string n,int r,int a,int m1,int m2,int m3,int m4,int m5):test(n,r,a,m1,m2,m3,m4,m5)
		{
		    test::display();
			int t;
			float p;
			t=m1+m2+m3+m4+m5;
			p=t/5;
			cout<<"\nthe total is\n"<<t<<endl;
			cout<<"\nthe percentage is\n"<<p<<endl;
			if(t<=499 && t>=400)
			{
				cout<<"grade is O"<<endl;
			}
			else if(t<=399 && t>=300)
			{
				cout<<"grade is E"<<endl;
			}
			else if(t<=299 && t>=200)
			{
				cout<<"grade is A"<<endl;
			}	
		}
};
int main()
{
	string s,co;
    int ro,ag;
    int mm1,mm2,mm3,mm4,mm5;
    cout<<"enter name: "<<endl;
	cin>>s;
	cout<<"enter roll: "<<endl;
	cin>>ro;
	cout<<"enter age: "<<endl;
	cin>>ag;
	cout<<"enter 5 marks: "<<endl;
	cin>>mm1>>mm2>>mm3>>mm4>>mm5;
	result t(s,ro,ag,mm1,mm2,mm3,mm4,mm5);
	return 0;
}