//5
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char ch;
    int c=0,w=0,l=0,ul=0,ll=0,d=0,sp=0;
    ifstream in("Text.txt");
    in.get(ch);
    while(!in.eof())
    {
        if(ch>=65 && ch<=90)
        {
            c++; ul++;
        }
        else if(ch>=97 && ch<=122)
        {
            c++; ll++;
        }
        else if(ch==' ')
          w++;
        else if(ch=='\n')
        {
            l++;w++;
        }
        else if(ch>='0' && ch<='9')
          d++;
        else
          sp++;
        in.get(ch);
    }
    w=w+1; l=l+1;
    in.close();
    cout<<"Number of characters: "<<c<<endl;
    cout<<"Number of words: "<<w<<endl;
    cout<<"Number of lines: "<<l<<endl;
    cout<<"Number of upper case letters: "<<ul<<endl;
    cout<<"Number of lower case letters: "<<ll<<endl;
    cout<<"Number of digits: "<<d<<endl;
    cout<<"Number of special symbols: "<<sp<<endl;
}