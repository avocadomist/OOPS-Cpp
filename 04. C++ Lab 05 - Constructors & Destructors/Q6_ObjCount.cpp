#include <iostream>
using namespace std;

class obj
{
	int i;
	static int c;
	
	public:
	obj()
	{
		i=0;
		c++;
	}
	
	obj(int x)
	{
		i=x;
		c++;
	}
	
	obj(const obj &p)
	{
		i=p.i;
		c++;
	}	
	
	static void count()
	{
		cout<<"Count number of objects created: "<<c<<endl;
	}
};

int obj :: c;

int main()
{
	obj o1, o2(6), o3(o2), o4, o5(o3);
	obj :: count();
	
	return 0;
}


