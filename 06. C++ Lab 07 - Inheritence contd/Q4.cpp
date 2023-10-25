#include <iostream>
using namespace std;
class shape
{
	public:
	shape()
	{
	}
};
class circle:public shape
{
	int radius;
	public:
		circle(int r):shape()
		{
			radius=r;
			cout<<"\narea of circle:\n"<<(3.14*radius*radius);
		}
};
class rectangle:public shape
{
	int length,breadth;
	public:
		rectangle(int l,int b):shape()
		{
			length=l;
			breadth=b;
			cout<<"\narea of rectangle:\n"<<length*breadth;
		}
};
class triangle:public shape
{
	int height,base;
	float a;
	public:
		triangle(int h,int b):shape()
		{
			height=h;
			base=b;
			a=0.5*height*base;
			cout<<"\narea of triangle:\n"<<a;
		}
};
int main()
{
	int len,br,hei,bs;
	int radi;
	cout<<"enter radius:"<<endl;
	cin>>radi;
	cout<<"enter length:"<<endl;
	cin>>len;
	cout<<"enter breadth:"<<endl;
	cin>>br;
	cout<<"enter height:"<<endl;
	cin>>hei;
	cout<<"enter base:"<<endl;
	cin>>bs;
	circle c(radi);
	rectangle r(len,br);
	triangle t(hei,bs);
}