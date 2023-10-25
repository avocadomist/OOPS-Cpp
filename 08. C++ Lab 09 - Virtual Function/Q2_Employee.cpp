#include <iostream>
using namespace std;


class Employee
{
    protected:
        string name; 
        int id;
        double salary;
    
    public:
    	virtual void get()
    	{
    		cout<<"enter name: ";
			cin>>name;
			cout<<"enter id: ";
			cin>>id;
			cout<<"enter salary: ";
    		cin>>salary;
		}
		
		virtual void display()
		{
			cout<<"\n\nName: "<<name<<endl;
			cout<<"Id: "<<id<<endl;
			cout<<"Salary: "<<salary<<endl; 
		}
};


class Regular: public Employee
{
    double DA;	
    double HRA;
    double basic_salary;
        
    public:
    void get(double d, double h, double b)
	{
        DA=d;
        HRA=h;
        basic_salary=b;
    }
     
    void display()
	{
        cout<<"Salary of the Regular employee is "<<(DA+HRA+basic_salary);
    }
    
};


class PartTime: public Employee
{
    private:
        int number_of_hours;
        double pay_per_hour;
    public:
        void get(int nh, double p)
		{
            number_of_hours=nh;
            pay_per_hour=p;
        }
        
        void display()
		{
            cout<<"\nSalary of the part-time employee is "<<(number_of_hours*pay_per_hour);
        }
};


int main()
{
    Employee e;
    e.get();
	Regular r;
	r.get(22000.0,13000.0,10000.50);   
    PartTime pt;
	pt.get(12,2000);
    
    Employee* p[3];
    p[0]=&e;
	p[1]=&r;
	p[2]=&pt;
	
	for (int i=0; i<3; i++)
	{
		p[i]->display();
	}
	
	return 0;
}
