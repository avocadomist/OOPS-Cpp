#include <iostream>
using namespace std;


class Employee
{
    protected:
        string name; 
        int id;
        double salary;
    
    public:
    	Employee(string n, int i, double sa)
    	{
    		name=n;
    		id=i;
    		salary=sa;
		}
		
		void display()
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
    Regular(string n, int i, double sa, double d, double h, double b):Employee (n, i, sa)
	{
        DA=d;
        HRA=h;
        basic_salary=b;
    }
     
    void display()
	{
		Employee::display();
        cout<<"Salary of the Regular employee is "<<(DA+HRA+basic_salary);
    }
    
};


class PartTime: public Employee
{
    private:
        int number_of_hours;
        double pay_per_hour;
    public:
        PartTime(string n, int i, double sa, int nh, double p):Employee (n, i, sa)
		{
            number_of_hours=nh;
            pay_per_hour=p;
        }
        void display()
		{
			Employee::display();
            cout<<"Salary of the part-time employee is "<<(number_of_hours*pay_per_hour);
        }
};


int main()
{
    Regular r("Sud",210, 50000.50, 2000.0,3000.0,10000.50);
    r.display();
    
    PartTime p("Dev",211, 35000.40,8,800);
    p.display();


    return 0;
}
