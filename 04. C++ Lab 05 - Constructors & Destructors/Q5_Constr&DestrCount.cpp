#include <iostream>
using namespace std;

class A
{
	int i;
	static int c;
	
	public:
	A()
	{
		i=0;
		cout<<"Object - "<< ++c <<" created."<< endl;
	}
	
	A(int p)
	{
		i=p;
		cout<<"Object - "<< ++c <<" created."<< endl;
	}
	
	A(const A &ob)
	{
		i=ob.i;
	}
	
	~A()
	{
		cout<<"Object - "<< c-- <<" destroyed."<< endl;
	}
};

int A :: c = 0;

int main()
{
	A a1, a2(7), a3(a2);
	int j=1;
	
	if(j)
	{
		A a4(a3), a5;
		a5=a4;
	}
	
	return 0;
}



