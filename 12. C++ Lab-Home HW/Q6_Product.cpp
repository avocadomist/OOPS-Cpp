#include<iostream>
#include<fstream>
using namespace std;
class PROD
{
	int PCODE;
	string DESC;
	int stock;
	public:
		void getinfo()
		{
			cout<<"Enter product code: ";
			cin>>PCODE;
			cout<<"Enter name: ";
			cin>>DESC;
			cout<<"Enter stock: ";
			cin>>stock;
		}
		void display()
		{
			cout<<"\nProduct code: "<<PCODE<<"\nProduct name: "<<DESC<<"\nStock: "<<stock;
		}
		int returncode()
		{
			return PCODE;
		}
};
int main()
{
	int n,c,loc;
	fstream f1;
	cout<<"Enter no. of products: ";
	cin>>n;
	f1.open("PRODUCT.dat",ios::out|ios::binary);
	PROD p[n],p1[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nProduct "<<i+1<<endl;
		p[i].getinfo();
		f1.write((char*)&p[i],sizeof(p[i]));
	}
	f1.close();
	f1.open("PRODUCT.dat",ios::in|ios::ate|ios::binary);
	f1.seekg(0);
	for(int i=0;i<n;i++)
	{
		f1.read((char*)&p1[i],sizeof(p1[i]));
		p1[i].display();
	}
	f1.seekg(0);
	cout<<"\nEnter product code to be updated: ";
	cin>>c;
	for(int i=0;i<n;i++)
	{
		f1.read((char*)&p1[i],sizeof(p1[i]));
		if(p1[i].returncode()==c)
		{
			if(f1.eof())
				f1.clear();
			loc=(i-1)*sizeof(p1[i]);
			f1.seekp(loc);
			cout<<"\nEnter details to be updated:\n";
			p1[i].getinfo();
			f1.write((char*)&p1[i],sizeof(p1[i]))<<flush;
		}
	}
	f1.seekg(0);
	cout<<"Updated item: ";
	for(int i=0;i<n;i++)
	{
		f1.read((char*)&p1[i],sizeof(p1[i]));
		p1[i].display();
	}
	f1.close();
}