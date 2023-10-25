#include<iostream>
#include<string.h>
using namespace std;

template<class t>

class array
{
    t a[30],se;int size;
	
	public:
	void get()
	{
		cout<<"\nEnter the size of array: ";
		cin>>size;
		
		cout<<"\n Enter "<<size<<" elements: \n";
		for(int i=0;i<size;i++)
        {
        	cin>>a[i];
		}
}

void search()
{
	cout<<"\nEnter the elements to search: ";
	cin>>se;

    int f=0;
    for(int i=0;i<size;i++)
    {
    	if(a[i]==se)
        {
            f=1;
			cout<<"Element found at position "<<i+1;

            break;
        }
	}

    if(f==0)
	cout<<"Element not found";
}

};

 

int main()
{

    array<int>objin;
    array<char>objch;

    cout<<"\nSearching integers";

    objin.get();
    objin.search();

    cout<<"\n\nSearching characters";    

    objch.get();
    objch.search();    

    return 0;

}
