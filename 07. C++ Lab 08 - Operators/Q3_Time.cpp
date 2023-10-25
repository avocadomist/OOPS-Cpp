#include <iostream>
using namespace std;

class time
{
	int hr, min, sec;
	
	public:
	time (int h=0, int m=0, int s=0)
	{
		hr=h;
		min=m;
		sec=s;
	}
	
	void display()
	{
		cout<<"Time: "<<hr<<"hrs "<<min<<"mins "<<sec<<" secs"<<endl;
	}
	
	time operator ++()
	{
		++hr;
		++min;
		++sec;
		
		return *this;
	}
	
	time operator --()
	{
		--hr;
		--min;
		--sec;
		
		return *this;
	}
	
	friend time operator ++(time &t, int)
	{
		time tm;
		tm.hr = t.hr++;
		tm.min = t.min++;
		tm.sec = t.sec++;
		
		return tm;
	}
	
	friend time operator --(time &t, int)
	{
		time tm;
		tm.hr = t.hr--;
		tm.min = t.min--;
		tm.sec = t.sec--;
		
		return tm;
	}
};


int main()
{
	time t1(5,15,54), t2, t3, t4, t5;
	t2 = ++t1;
	t3 = --t1;
	t4 = t1++;
	t5 = t1--;
	
	t1.display();
	t2.display();
	t3.display();
	t4.display();
	t5.display();
	
	return 0;
}


