#include<iostream>
#include<string.h>
using namespace std;
class media{
    protected:
    string title;
    float price;
    public:
    media(string s, float a){
        title=s;
        price=a;
    }
    virtual void display(){}
};
class book:public media{
    int pages;
    public:
    book(string s, float a, int p):media(s,a){
        pages=p;
    }
    void display(){
        cout<<"\nTitle: "<<title;
        cout<<"\nPages: "<<pages;
        cout<<"\nPrice: "<<price;
    }
};

class tape:public media
{
    float time;
    public:
    tape(string s, float a, float t):media(s,a){
        time=t;
    }

 void display(){
        cout<<"\n\nTitle: "<<title;
        cout<<"\nPlay time: "<<time<<"mins";
        cout<<"\nPrice: "<<price;

    }
};

int main(){
    book book1("C++",450,350);
    tape tape1("C",90,55);
    media *list[2];
    list[0]=&book1;
    list[1]=&tape1;
    list[0]->display();
    list[1]->display();
    return 0;
}