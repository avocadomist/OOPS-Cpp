#include <iostream>
using namespace std;

class Array
{
	int *p;
	int n;
	
	public:
	Array ()
	{
		n=0;
	}
	
	Array (int);
	void display();
	void add(Array, Array, Array);
};

Array :: Array (int m)
{
	n=m;
	p = new int [m];
	cout<<"Enter "<<m<<" elements: \n";
	
	int i;
	for(i=0;i<m;i++)
	cin>>p[i];
}

void Array :: add(Array O1, Array O2, Array O3)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		O3.p[i] = O1.p[i] + O2.p[i];
	}
}

void Array :: display()
{
	int i;
	for(i=0;i<n;i++)
	cout<<p[i]<<" "<<endl;
}



int main()
{
	int size;
	cout<<"\nEnter no. of elements: ";
	cin>>size;
	
	Array A1(size), A2(size), A3;
	A1.display();
	A2.display();
	
	A3.add(A1, A2, A3);
	A3.display();
	
	return 0;
}




