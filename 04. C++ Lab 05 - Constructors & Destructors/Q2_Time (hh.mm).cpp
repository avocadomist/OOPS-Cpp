#include <iostream>
using namespace std;

class Time
{
	int hr, min;
	
	public:
	Time()
	{
		hr=0;
		min=0;
	}
	
	Time(int h, int m=0)
	{
		hr=h;
		min=m;
	}
	
	Time(const Time &T)
	{
		hr=T.hr;
		min=T.min;
	}
	
	void display()
	{
		cout<<"Time is: "<<hr<<":"<<min<<endl;
	}
};

int main()
{
	Time t1, t2(22,42), t3(12), t4(t2);
	t1.display();
	t2.display();
	t3.display();
	t4.display();
	
	return 0;
}

