#include <iostream>
#include <string>

using namespace std;
class book
{
    string name;
    string author;
    int price;

public:
    void input()
    {
        cout << "Enter book name: ";
        cin>> name;
        cout << "Enter author name: ";
        cin>> author;
        cout << "Enter book price: ";
        cin >> price;
    }
    void display(book *, int, int, int);
};

class B
{
public:
    friend void book::display(book *, int, int, int);
};
void book::display(book *b, int n, int l, int u)
{
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i].price >= l && b[i].price <= u)
            {
                cout << b[i].name << "\t\t" << b[i].author << "\t\t" << b[i].price << endl;
            }
        }
    }
}

int main()
{
    int n, l, u;
    cout << "Enter the number of books: ";
    cin >> n;
    book b[n], a;
    for (int i = 0; i < n; i++)
    {
        cout << "For book " << i + 1<<endl;
        b[i].input();
    }
    cout << "\nEnter lower range: ";
    cin >> l;
    cout << "Enter upper range: ";
    cin >> u;
    cout << "Name\t\tAuthor\t\tPrice\n";
	cout << "------------------------------------------\n";
	
    a.display(b, n, l, u);
    
    return 0;
}