//2
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char ch;
    ifstream in;
    ofstream out("New.txt");
    in.open("hello.txt");
    in.get(ch);
    while(!in.eof())
    {
        out<<ch;
        in.get(ch);
    }
    cout<<"Copied"<<endl;
    in.close();
    out.close();
}