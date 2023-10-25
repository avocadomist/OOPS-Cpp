#include<iostream>
#include<fstream>
using namespace std;
class student{
	int addno;
	char name[90];
	float totalmarks;
	public:
		void getinfo()
		{
			cout<<"Enter roll number, name and total marks: ";
			cin>>addno>>name>>totalmarks ;
		}
		void showinfo ()
		{
			cout<<"\nRoll Number: "<<addno<<"\nName: "<<name<<"\nTotal marks: "<<totalmarks<<endl;
		}
		float rettotmarks ()
		{
			return totalmarks;
		}
};

int main()
{
	int n,i;
	fstream f;
	
	f.open("studfile.dat", ios::out | ios::binary);
	
	cout<<"Enter the no. of students: ";
	cin>>n;
	student d[n];
	cout<<"Enter the details: ";
	for(i=0;i<n;i++)
	{
		cout<<"\nStudent "<<i+1<<endl;
		d[i].getinfo();
		f.write((char*)&d[i], sizeof(d[i]));
	}
	f.close();
	
	f.open("studfile.dat", ios::in|ios::binary);
	
	cout<<"\nScore between 456 & 498 secured by:\n";
	for(i=0;i<n;i++)
	{
		f.read((char*)&d[i], sizeof(d[i]));
		float tmarks=d[i].rettotmarks();
		
		if(tmarks>=456 && tmarks<=498)
			d[i].showinfo();
	}
	
	f.close();
	return 0;
}