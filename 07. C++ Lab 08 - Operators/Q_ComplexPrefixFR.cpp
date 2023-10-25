#include <iostream>
using namespace std;

class complex
{
	int r, i;
	
	public:
	complex (int a=0, int b=0)
	{
		r=a;
		i=b;
	}
	
	friend complex operator ++(complex &t)
	{
		++t.r;
		++t.i;
		
		return t;
	}
	
	void display()
	{
		cout<<r<<" + i"<<i<<endl;
	}
};

int main()
{
	complex c1, c2(3,2);
	c2.display();
	
	c1 = ++c2;
	
	c1.display();
	c2.display();
		
	return 0;
}




