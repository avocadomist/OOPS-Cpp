#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
using namespace std;

class Directory
{
    char Name[20];
    char Address[30];
    char areacode[10];
    char phno[15];
    
    public:
    void registers();
    void show();
    
    int checkcode(char AC[])
    {
        return(strcmp(areacode,AC));
    }
    char* returnareacode(){
        return areacode;
    }
    char* returnpho(){
        return phno;
    }
};

void Directory::registers()
{
    cout<<"\nEnter name: ";
    cin>>Name;
    cout<<"\nEnter address: ";
    cin>>Address;
    cout<<"\nEnter 3 digit area code: ";
    cin>>areacode;
    cout<<"\nEnter phone number: ";
    cin>>phno;
}

void Directory::show(){
    cout<<"\nName: "<<Name<<"\nAddress: "<<Address<<"\nAreacode: "<<areacode<<"\nPhone No.: "<<phno;
}

void display()
{
    Directory s2;
    fstream f;
    cout<<"\nDETAILS:";
    f.open("TELE.dat",ios::in);
    f.seekg(0,ios::beg);
    while(f.read((char *) &s2, sizeof(s2))){
        s2.show();
    }
    f.close();
}

void entry(){
    Directory d1;
    fstream f;
    f.open("TELE.dat",ios::in|ios::out|ios::ate|ios::binary);
    if(!f)
	{
        f.close();
        f.open("TELE.dat",ios::out);
        f.close();
        f.open("TELE.dat",ios::in|ios::out|ios::ate|ios::binary);
    }
    while(f.read((char *) &d1, sizeof(d1))){}
    f.clear();
    d1.registers();
    f.write((char *) &d1, sizeof(d1));
    f.close();
    display();
}

void areacodesort(){
    Directory s1;
    fstream f;
    f.open("TELE.dat",ios::in|ios::out|ios::ate|ios::binary);
    if(!f){
        f.close();
        f.open("TELE.dat",ios::out);
        f.close();
        f.open("TELE.dat",ios::in|ios::out|ios::ate|ios::binary);
    }
    f.seekg(0,ios::beg);
    while(f.read((char *) &s1, sizeof(s1))){}
    f.clear();
    int location=f.tellg();
    cout<<"\nLocation :"<<location;
    int objn=location/sizeof(s1);
    cout<<"\nNo. of entries: "<<objn;
    
    Directory s[objn];
    f.seekg(0,ios::beg);
    for(int i=0;i<objn;i++){
        f.read((char *) &s[i], sizeof(s[i]));
    }
    Directory temp;
    for(int i=0;i<objn-1;i++){
        for(int j=0;j<objn-i-1;j++){
            if (strcmp(s[j].returnareacode(),s[j+1].returnareacode())>0){
                temp = s[j]; 
                s[j] = s[j+1]; 
                s[j+1] = temp; 
            }
        }
    }
    f.clear();
    f.seekp(0,ios::beg);
    for(int i=0;i<objn;i++){
        f.write((char *) &s[i], sizeof(s[i]));
    }
    f.close();
    cout<<"\nCode wise sort: \n";
    display();

}

void delentry(){
    fstream f1,f2;
    char ph[15];
    cout<<"\nEnter ph no. of entry to be deleted: ";
    cin>>ph;
    f1.open("TELE.dat",ios::in|ios::out|ios::ate|ios::binary);
    f2.open("temptele.dat",ios::out);
    f1.seekg(0,ios::beg);
    f2.seekp(0,ios::beg);
    Directory s;
    while(f1.read((char *) &s, sizeof(s))){
        if(strcmp(ph,s.returnpho())!=0){
            f2.write((char *) &s, sizeof(s));
        }
        else{
            cout<<"\n ENTRY FOUND TO BE DELETED.";
            s.show();
        }
    }
    f1.close();
    f2.close();
    remove("TELE.dat");
    rename("temptele.dat","TELE.dat");
    display();

}

void copy()
{
    fstream f1,f2;
    char c[10]="123";
    f1.open("TELE.dat",ios::in|ios::out|ios::ate|ios::binary);
    f2.open("TELEBACK.dat",ios::out);
    f1.seekg(0,ios::beg);
    f2.seekp(0,ios::beg);
    Directory s;
    while(f1.read((char *) &s, sizeof(s))){
        if(s.checkcode(c)==0){
            cout<<"\nCoping... ";
            s.show();
            f2.write((char *) &s, sizeof(s));
        }
    }
    f2.clear();
    f2.close();
    cout<<"\nCopied file:";
    f2.open("TELEBACK.dat",ios::in);
     while(f2.read((char *) &s, sizeof(s))){
        s.show();
    }
    f2.close();

}

int main(){
    int ch=1;
    while(ch!=0){
        cout<<"\n\nOperations to perform on TELE.DAT";
        cout<<"\n1.New entry\n2.Sorting entries\n3.Insert entry in right position\n4.Deletion of entry\n5.Copy\n0.Exit..";
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                entry();
                break;
            case 2:
                areacodesort();
                break;
            case  3:
                entry();
                areacodesort();
                break;
            case 4:
                delentry();
                break;
            case 5:
                copy();
        }
    }
}