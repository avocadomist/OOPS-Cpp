#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream of("PRODUCT");

    cout<<"Enter item name: ";
    char name[30];
    cin>> name;

    of<<name<<endl;

    cout<<"Enter item cost: ";
    float cost;
    cin>>cost;
	
	of<<cost<<endl;
	
	of.close();
	
	ifstream inf("PRODUCT");
	
	inf>>name;
	inf>>cost;
	
	cout<<"\nItem name: "<<name<<endl;
	cout<<"Item cost: "<<cost<<endl;
	
	inf.close();
	
	return 0;
}

