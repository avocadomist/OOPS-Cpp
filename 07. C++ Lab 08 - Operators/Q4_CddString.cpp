#include<iostream>
#include<string.h>
using namespace std;

class join
{
	int n;
	char *c;
	
	public:
		join(int x=0,char *ch="")
		{
			n=x;
			c=new char[n+1];
			strcpy(c,ch);
		}
		
		join operator +(join o)
		{
			int i,j;
			join t;
			for(i=0;i<n;i++)
			    t.c[i]=c[i];
			for(j=0;j<o.n;j++)
			{
				t.c[i]=o.c[j];
				i++;
			}
			return t;
		}
		
		void display()
		{
			cout<<"\n\nThe concatenated string is "<<c<<endl;
		}
		
		~join(){}
};


int main()
{
	char *s1=new char;
	char *s2=new char;
	cout<<"Enter first string :";
	cin>>s1;
	cout<<"Enter second string :";
	cin>>s2;
	
	int l1=strlen(s1);
	int l2=strlen(s2);
	join o1(l1,s1),o2(l2,s2),o3(l1+l2);
	o3=o1+o2;
	o3.display();
	return 0;
}