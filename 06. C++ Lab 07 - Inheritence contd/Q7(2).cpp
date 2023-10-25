#include <iostream>
#include<string.h>
using namespace std;
class Batsman
{
    protected:
    int runs;
    int half_centuries;
    int centuries;
    int strike_rate;
    float avg;
    public:
    Batsman(int r,int hc,int c,int sr,float a)
    {
        runs=r;
        avg=a;
        half_centuries=hc;
        centuries=c;
        strike_rate=sr;
    }
    void bat_dis()
    {
        cout<<"-----------BATSMAN-----------"<<endl;
        cout<<"Runs taken:"<<runs<<endl;
        cout<<"Batting average:"<<avg<<endl;
        cout<<"Number of half centuries:"<<half_centuries<<endl;
        cout<<"Number of centuries made:"<<centuries<<endl;
        cout<<"Strike rates:"<<strike_rate<<endl;
        cout<<"--------------------------------"<<endl;
    }
};
class Baller
{
    protected:
    string pace,cricket;
    int wickets;
    int run;
    int speed;
    int no_of_hatricks;
    public:
    Baller(string p,string cr,int w,int rr,int s,int h)
    {
        pace=p;
        wickets=w;
        run=rr;
        speed=s;
        no_of_hatricks=h;
        cricket=cr;
    }
    void ball_dis()
    {
     ;
        cout<<"----------------BALLER---------------"<<endl;
        cout<<"Bowler:"<<pace<<endl;
        cout<<"Number of wickets taken:"<<wickets<<endl;
        cout<<"Runrate:"<<run<<endl;
        cout<<"Speed:"<<speed<<endl;
        cout<<"Number of hatricks made:"<<no_of_hatricks<<endl;
        cout<<"Best figure:"<<cricket<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<endl;
    }
};
class Allrounder:public Batsman,public Baller
{
    private:
    int man_of_match;
    int intl;
    int catches;
    int icc;
    string stylish;
    public:
    Allrounder(int r,int hc,int c,int sr,float a,string p,string cr,int w,int rr,int s,int h,int mm,int im,int ca,int ic,string st):Batsman(r,hc,c,sr,a),Baller(p,cr,w,rr,s,h)
    {
     
        man_of_match=mm;
        intl=im;
        catches=ca;
        icc=ic;
        stylish=st;
    }
    void display()
    {
        cout<<"-------------ALLROUNDER----------"<<endl;
        cout<<"The number of man of matches being made:"<<man_of_match<<endl;
        cout<<"Number of international matches played:"<<intl<<endl;
        cout<<"Number of catches made:"<<catches<<endl;
        cout<<"ICC RANKING'S position:"<<icc<<endl;
        cout<<"Stylish player of the match:"<<stylish<<endl;
        cout<<"------------------------------------"<<endl;
    }
};
int main()
{
    Batsman b(100,34,10,6,7);
    Baller ba("abc","bowler",7,4,3,8);
    Allrounder ar(100,34,10,6,7,"abc","bowler",7,4,3,8,2,1,5,9,"def");
    b.bat_dis();
    ba.ball_dis();
    ar.display();
    return 0;
}