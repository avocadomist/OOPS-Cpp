#include <iostream>
#include <string.h>
using namespace std;

class Str
{
	char *word;
	int len;
	
	public:
	Str()
	{
		word=new char;
		len=0;
	}
	
	Str(char *s, int n)
	{
		len=n;
		word=new char[len+1];
		strcpy(word,s);
	}
	
	void addstring(char *s)
	{
		string w = word[len] + s;
        cout<<"\nCombined string : "<<w;
	}
	
	void display()
	{
		cout<<word;
	}
	
	~Str()
	{
		cout<<"\nDestructor invoked"<<endl;
	}
};

int main()
{
	Str s1("Buns",4);
	
	s1.addstring("Sweet");
	s1.display();
	
	return 0;
}



