
#include <iostream>
using namespace std;

class student
{
	protected:
	int roll, age;
	string name;
	string course;
	
	public:
	void s_get()
	{
		cout<<"\nEnter name: ";
		cin>>name;
		cout<<"Enter age: ";
		cin>>age;
		cout<<"Enter roll: ";
		cin>>roll;
		cout<<"Enter course: ";
		cin>>course;
	}	
	
	void display()
	{
		
	}
};

class test : public student
{
	int marks[5];
	
	public:
	void t_get()
	{
		cout<<"\nEnter marks in 5 subjects: \n";
		cin>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4];
	}
	
	int t_tot()
	{
		return (marks[0]+marks[1]+marks[2]+marks[3]+marks[4]);
	}	
};