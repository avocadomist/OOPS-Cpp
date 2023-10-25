#include <iostream>
using namespace std;

class mcm
{
	int m,cm;
	
	public:
	mcm(int a=0,int b=0)
	{
		m=a;
		cm=b;
	}
	
	void display()
	{
		cout<<m<<"m "<<cm<<"cm."<<endl;
	}

};

class finch
{
	int f, i;
	
	public:
		finch(int a=0, int b=0)
		{
			f=a;
			i=b;
		}
		
		void display()
		{
			cout<<f<<" feet "<<i<<" inches "<<endl;
		}
		
		int getin()
		{
			return i;
		}
		
		int getfeet()
		{
			return f;
		}
		
		operator const mcm()
		{
			int d1=f*12+i;
			float d2=d1*2.54;
			
			int m1=d2/100;
			int cm1=d2-m1*100;
			
			return mcm(m1,cm1);
		}		
};

int main()
{
	finch ob(8,9);
	mcm obb;
	
	obb=ob;
	
	obb.display();
	ob.display();
	
	return 0;
}