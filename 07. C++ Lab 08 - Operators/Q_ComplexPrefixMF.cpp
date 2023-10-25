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
	
	void display()
	{
		cout<<r<<" + i"<<i<<endl;
	}
	
	complex operator ++ ()
	{
		++r;
		++i;
		
		return *this;
	}
};

int main()
{
	complex c1, c2(3,2), c3;
	c1 = ++c2;
	
	c1.display();
	c2.display();
	c3.display();
	
	return 0;
}




