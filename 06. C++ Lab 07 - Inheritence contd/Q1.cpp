#include <iostream>

using namespace std;
class student
{
	string name;
	int roll;
	int age;
	string course;
	public:
		student(string n,int r,int a,string c)
		{
		    name=n;
		    roll=r;
		    age=a;
		    course=c;
		}
		void display()
		{
			cout<<"name:"<<name<<endl;
			cout<<"roll:"<<roll<<endl;
			cout<<"age:"<<age<<endl;
			cout<<"course:"<<course;
		}
};
class test:public student
{
	int marks[5];
	public:
		test(string n,int r,int a,string c,int m1,int m2,int m3,int m4,int m5):student(n,r,a,c)
		{
		    marks[0]=m1;
		    marks[1]=m2;
		    marks[2]=m3;
		    marks[3]=m4;
		    marks[4]=m5;
		}
		void display()
		{
		    cout<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<" "<<marks[3]<<" "<<marks[4];
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
	cout<<"enter course: "<<endl;
	cin>>co;
	cout<<"enter 5 marks: "<<endl;
	cin>>mm1>>mm2>>mm3>>mm4>>mm5;
	test t(s,ro,ag,co,mm1,mm2,mm3,mm4,mm5);
	
	cout<<"display data"<<endl;
	t.student::display();
	t.display();
	return 0;
	
}