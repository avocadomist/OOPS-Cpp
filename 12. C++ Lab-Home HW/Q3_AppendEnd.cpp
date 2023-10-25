#include<iostream>
#include<fstream>
using namespace std;
class STUD 
{
	int Rno;
	string name;
	public:
		void Enter()
		{
			cout<<"Enter details: ";
			cout<<"\nEnter Name and Roll Number: ";
			cin>>name>>Rno;
		}
		void Display()
		{
			cout<<"\nRoll Number: "<<Rno<<"\nName: "<<name<<endl;
		}
};

int main()
{
	fstream f;
	STUD s[2];
	s[0].Enter();
	f.open("STUD.dat",ios::out|ios::binary);
	f.write((char*)&s[0],sizeof(s[0]));
	f.close();
	
	f.open("STUD.dat",ios::app|ios::in|ios::binary);
	s[1].Enter();
	f.write((char*)&s[1],sizeof(s[1]));
	f.close();
	
	for(int i=0;i<2;i++)
	{
		f.open("STUD.dat",ios::in|ios::binary);
		f.read((char*)&s[i],sizeof(s[i]));
		s[i].Display();
	}
	f.close();
	
	return 0;
}