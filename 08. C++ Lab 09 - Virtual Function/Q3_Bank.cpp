# include<iostream>
# include<string.h>

using namespace std;

class account
{
    protected:
    int acc_no;
    int remaining_balance;
    int curr_amount1;
    string name;
    float balance;

    public:
    virtual void getdata()
    {
        cout<<"Enter the name of the customer "<<endl;
        cin>>name;
        
        cout<<"Enter the account number \n"<<endl;
        cin>>acc_no;
        
        float a;
        cout<<"Enter the balance "<<endl;
        cin>>a;
        
        if(a<500)
        {
            cout<<"Minimum amount should be 500 "<<endl;
        }
        else
        {
            cout<<"Account created with "<<a<<"rupees"<<endl;
            balance=a;
        }
        
    }

    virtual void display()
    {
        cout<<"Account number = "<<acc_no<<endl;
        cout<<"Customer name = "<<name<<endl;
        cout<<"The current balance = "<<balance<<endl;
    }
 };

 class savings:public account
 {
    protected:
    float amount;
    float withdraw_amm;
    int id;
    public:
    void getdata()
    {
        int ch,c=0;
        
        while(c==0)
        {
            cout<<"1) to deposit money\n2) to withdraw\n3) exit\nenter choice: "<<endl;
            scanf("%d",&ch);
            
            switch(ch)
            {
                case 1:
                cout<<"Enter the amount to deposit in your current account "<<endl;
                cin>>amount;
                balance=balance+amount;
                cout<<balance<<endl;
                break;

                case 2:
                cout<<"Enter the amount you want to wiuthdaw \n";
                cin>>withdraw_amm;
                if(balance-withdraw_amm>600)
                {
                    cout<<"Your transacrtion is successfully completed "<<endl;
                    cout<<"Your remaining amount is ="<<balance-withdraw_amm<<endl;
                    remaining_balance=balance-withdraw_amm;
                    cout<<"Money debited as caution amount for emertgency "<<endl;
                }
                else
                {
                    remaining_balance=balance-withdraw_amm;
                    cout<<"The transaction can not be completed but -->> minimum balance should be 600 !!\n";
                }
                break;


                case 3:
                c++;
                break;
            }
        }
    }

    void display()
    {
        cout<<"Customer name = "<<name<<endl;
        cout<<"Displaying the information "<<endl;
        cout<<"Account number = "<<acc_no<<endl;
        cout<<"tHE CURRENT AMOUNT = "<<balance<<endl;
        cout<<"The ramining balnce = "<<remaining_balance<<endl;
        cout<<"The current initial balance = "<<balance<<endl;
        cout<<"Amount diposited= "<<amount<<endl;
        cout<<"Withdraw amount = "<<withdraw_amm<<endl;
    }

 };

 class current:public account
 {
    protected:
    int caution_amm;
    float amount;
    float withdraw_amm;
    int id;
    public:
    void getdata()
    {

        int a,c=0;
        
        while(c==0)
        {
            cout<<"\n1) to deposit money\n2) to withdraw\n3) exit\nenter choice: "<<endl;
            scanf("%d",&a);
            switch(a)
            {
                case 1:
                cout<<"Enter the amount to deposit in your current account "<<endl;
                cin>>amount;
                balance=balance+amount;
                cout<<balance<<endl;
                break;

                case 2:
                cout<<"Enter the amount you want to wiuthdaw \n";
                cin>>withdraw_amm;
                if(balance-withdraw_amm>600)
                {
                    cout<<"Your transacrtion is successfully completed "<<endl;
                    cout<<"Your remaining amount is ="<<balance-withdraw_amm<<endl;
                    remaining_balance=balance-withdraw_amm;
                    cout<<"Money debited as caution amount for emergency "<<endl;
                }
                else
                {
                    cout<<"The transaction can not be completed \nMinimum balance should be 600!!\n";
                }
                break;


                case 3:
                c++;
                break;
            }
        }

        
        cout<<"Enter the operation you want to perform "<<endl;
        
        int ch,flag=0;
        
        while(flag==0)
        {
            cout<<"Press: 1) for overdue amount \n2) to show balance \n3) to terminate the process \n";
            cout<<"Enter the operation you want to perform "<<endl;
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                if(remaining_balance<600)
                {
                    cout<<"Your overdue amount is = "<<remaining_balance<<"Less than 600 = "<<600-remaining_balance<<endl;
                    caution_amm=600-remaining_balance;
                }
                break;

                case 2:
                cout<<"Your remaining balance = "<<remaining_balance<<endl;
                break;

                case 3:
                flag++;
                break;
            }
           
        }
    }

    void display()
    {
        cout<<"Account number = "<<acc_no<<endl;
        cout<<"Customer name = "<<name<<endl;
        cout<<"The current initial balance = "<<balance<<endl;
        cout<<"The caurion amount = "<<caution_amm<<endl;
        cout<<"tHE CURRENT AMOUNT = "<<balance<<endl;
        cout<<"The ramining balnce = "<<remaining_balance<<endl;
        cout<<"The current initial balance = "<<balance<<endl;
        cout<<"Amount diposited= "<<amount<<endl;
        cout<<"Withdraw amount = "<<withdraw_amm<<endl;

    }

 };

 int main()
 {
    account *o1;
    savings o22;
    current o33;
    char acc[20];
    char str1[20]="savings";
    char str2[20]="current";
    cout<<"Enter wheteher the account is savings or current account"<<endl;
    cin.getline(acc,20);
    if(strcmp(str1,acc)==0)
    {
         o22.account::getdata();
         o22.account::display();
         o1=&o22;
         o1->getdata();
         o1->display();
    }
    else if(strcmp(str2,acc)==0)
    {
         o33.account::getdata();
         o33.account::display();
         o1=&o33;
         o1->getdata();
         o1->display();
    }
}