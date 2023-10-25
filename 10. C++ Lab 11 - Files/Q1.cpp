
//1
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char ch;
    ofstream out("hello.txt");
    out<<"Hello Friends";
    out.close();
    ifstream in;
    in.open("hello.txt");
    in.get(ch);
    while(!in.eof())
    {
        putchar(ch);
        in.get(ch);
    }
 
}