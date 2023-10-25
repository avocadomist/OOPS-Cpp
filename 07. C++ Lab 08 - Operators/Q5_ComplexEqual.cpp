
#include<iostream>
using namespace std;

class complex
{
	int r, i;

	public:
	complex (int rl=0, int im=0)
	{
		r=rl;
		i=im;
	}
	
	void display()
	{
		cout<<r<<"+"<<i<<"i"<<endl;
	}
	
	void operator =(complex &c)
	{
		r=c.r;
		i=c.i;
	}
	
	int operator==(complex &C)
	{
		if (r==C.r && i==C.i)
		return 1;
		else
		return 0;
	}
};

int main()
{
	complex c1(4,5), c2(4,5);
	
	cout<<"\nComplex no. 1: ";
	c1.display();
	cout<<"\nComplex no. 2: ";
	c2.display();
	
	if(c1==c2)
	cout<<"\nThey're equal";
	else
	cout<<"\nThey're not equal";
	
	return 0;
}






