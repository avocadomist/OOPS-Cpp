//6
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream in;
    in.open("New.txt");
    ofstream out("Text1.txt");
    char ch;
    in.get(ch);
    while(!in.eof())
    {
        if(ch>=65 && ch<=90)
          ch=ch+32;
        else if(ch>=97 && ch<=122)
          ch=ch-32;
        out<<ch;
        in.get(ch);
    }
    in.close(); out.close();
    in.open("Text1.txt");
    in.get(ch);
    while(!in.eof())
    {
        cout<<ch;
        in.get(ch);
    }
    in.close();
}