#include<iostream>
#include<fstream>
using namespace std;

class Applicant
{
	int Rno;
	char name[30];
	int A_score;
	public:
		void enroll()
		{
			cout<<"Enter Roll No., Name and Score out of 100: ";
			cin>>Rno>>name>>A_score;
		}
		void Status()
		{
			cout<<"\nRoll Number: "<<Rno<<endl<<"Name: "<<name<<endl<<"Score: "<<A_score;
		}
		int ReturnScore()
		{
			return A_score;
		}
};

int main()
{
	int n,i ;
	fstream f;
	
	f.open("APPLY.dat",ios::out|ios::binary);
	cout<<"Enter the number of applicants: ";
	cin>>n;
	Applicant a[n], b[n];
	cout<<"Enter details:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Applicant "<<i+1<<endl;
		a[i].enroll();
		f.write((char*)&a[i],sizeof(a[i]));
	}
	f.close();
	
	f.open("APPLY.dat",ios::in|ios::binary);
	cout<<"Applicants who scored above 70: ";
	for(i=0;i<n;i++)
	{
		f.read((char*)&b[i],sizeof(b[i]));
		int score = b[i].ReturnScore();
		if(score>=70)
			b[i].Status();
	}
	
	return 0;
}