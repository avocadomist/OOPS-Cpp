
#include <iostream>
using namespace std;

class student
{
	protected:
	int roll, age;
	string name;
	
	public:
	void s_get()
	{
		cout<<"\nEnter name: ";
		cin>>name;
		cout<<"Enter age: ";
		cin>>age;
		cout<<"Enter roll: ";
		cin>>roll;
	}	
};

class test : virtual public student
{
	int marks[3];
	
	public:
	void t_get()
	{
		cout<<"\nEnter marks in 3 subjects: \n";
		cin>>marks[0]>>marks[1]>>marks[2];
	}
	
	int t_tot()
	{
		return (marks[0]+marks[1]+marks[2]);
	}	
};

class activity : virtual public student
{
	int act[2];
	
	public:
	void a_get()
	{
		cout<<"\nEnter 2 activities: ";
		cin>>act[0]>>act[1];
	}	
	
	int a_tot()
	{
		return (act[0] + act[1]);
	}
};

class result : public test, public activity
{
	public:
	void display()
	{
		cout<<"\nRoll No. : "<<roll<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"Total score: "<<t_tot()+a_tot()<<endl;
		cout<<"Percentage: "<<((t_tot()+a_tot())/5.0)<<endl;
		
	}	
};

int main()
{
	result r;
	r.s_get();
	r.t_get();
	r.a_get();
	r.display();
}





