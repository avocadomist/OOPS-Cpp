#include<iostream>
#include<fstream>
using namespace std;
class DRINKS
{
	int DCODE;
	char DNAME[20]; 
	int DSIZE; 
	float DPRICE;
	
	public:
		void getdrinks( )
		{
			cout<<"Enter code, name, size in litres & price of the drink: ";
			cin>>DCODE>>DNAME>>DSIZE>>DPRICE;
		}
		void showdrinks( )
		{
			cout<<"\n\nCode: "<<DCODE<<"\nName: "<<DNAME<<"\nSize: "<<DSIZE<<"\nPrice: "<<DPRICE<<endl;
		}
		char *getname( )
		{
			return DNAME;
		}
};

int main()
{
	string name;
	int n,i;
	
	fstream f;
	f.open("drinksfile.dat", ios::out | ios::binary);
	cout<<"Enter the no. of drinks: ";
	cin>>n;
	DRINKS d[n];
	cout<<"Enter the details: ";
	for(i=0;i<n;i++)
	{
		cout<<"\nDrink "<<i+1<<endl;
		d[i].getdrinks();
		f.write((char*)&d[i], sizeof(d[i]));
	}
	f.close();
	
	f.open("drinksfile.dat", ios::in | ios::binary);
	for(i=0;i<n;i++)
	{
		f.read((char*)&d[i], sizeof(d[i]));
		name= d[i].getname();
		if(name=="cocacola")
		{
			d[i].showdrinks();
		}
	}
	f.close();
}