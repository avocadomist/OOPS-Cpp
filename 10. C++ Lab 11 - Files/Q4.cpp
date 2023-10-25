//4
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int i,j,n=0;
    char ch;
    ifstream in;
    in.open("New.txt");
    in.get(ch);
    while(!in.eof())
    {
        n++;
        in.get(ch);
    }
    for(i=0;i<n;i++)
    {
        in.close(); in.open("New.txt");
        for(j=0;j<n-i;j++)
           in.get(ch);
        cout<<ch;
    }
}