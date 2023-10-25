
#include<iostream>
using namespace std;


class Complex
{
	int real, img;
	
	public:
	Complex()
	{
		real=0;
		img=0;
	}
	
	Complex(int r, int i)
	{
		real = r;
		img = i;
	}

	Complex(const Complex &com)
	{
		real = com.real;
		img = com.img;
	}
	
	void display()
	{
		cout<< real<<" + "<<img<<"i"<< endl;
	}
	
	~Complex()
	{
		cout<<"Destructor invoked"<<endl;
	}
};

int main()
{
	Complex c1, c2(7,6), c3(c2), c4(1,2);
	
	c1.display();
	c2.display();
	c3.display();
	c4.display();
	
	return 0;
}


