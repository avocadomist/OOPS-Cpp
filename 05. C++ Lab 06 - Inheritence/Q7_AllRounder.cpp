#include<iostream>
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
    void bat_get()
    {
        cout<<"Enter the number of runs taken:"<<endl;
        cin>>runs;
        cout<<"Enter the batting average:"<<endl;
        cin>>avg;
        cout<<"Enter the number of half centuries made:"<<endl;
        cin>>half_centuries;
        cout<<"Enter the number of centuries made:"<<endl;
        cin>>centuries;
        cout<<"Enter the number of strike rate:"<<endl;
        cin>>strike_rate;
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
    string ps,cricket;
    int wickets;
    int run;
    int speed;
    int no_of_hatricks;
    public:
    void ball_get()
    {
        cin.ignore();
        cout<<"Enter what kind of bowler?"<<endl;
        getline(cin,ps);
        cout<<"Enter the number of wickets taken:"<<endl;
        cin>>wickets;
        cout<<"Enter the runrate:"<<endl;
        cin>>run;
        cout<<"Enter the speed rate:"<<endl;
        cin>>speed;
        cout<<"Enter the number of hatricks made:"<<endl;
        cin>>no_of_hatricks;
        cin.ignore();
        cout<<"The best figure name:"<<endl;
        getline(cin,cricket);
    }
    void ball_dis()
    {
     ;
        cout<<"----------------BALLER---------------"<<endl;
        cout<<"Bowler:"<<ps<<endl;
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
    void get()
    {
     
        cout<<"Enter the number of man of the matches achieved:";
        cin>>man_of_match;
        cout<<"Enter number of international matches played:";
        cin>>intl;
        cout<<"Enter number of catches made:";
        cin>>catches;
        cout<<"Enter the ICC RANKINGS position:";
        cin>>icc;
           cin.ignore();
        cout<<"Enter the stylish player of the match:"<<endl;
        getline(cin,stylish);
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
    Allrounder ar;
    ar.bat_get();
    ar.bat_dis();
    ar.ball_get();
    ar.ball_dis();
    ar.get();
    ar.display();
    return 0;
}