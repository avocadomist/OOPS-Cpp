#include <iostream>
#include <string>
using namespace std;
class student
{
    string name;
    int roll;
    int marks;
    static int avg;

public:
    void input()
    {
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter marks in OOP: ";
        cin >> marks;
    }
    static double AVGall(student s[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += s[i].marks;
        }
        
		s[n].avg = sum / (double)n;
	}
};
int student::avg;
int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    student s[n];
    for (int i = 0; i < n; i++)
    {
        cout << "For student " << i + 1 << "..\n";
        s[i].input();
    }
    cout << "The average marks of the students is: " << s[n].AVGall(s, n);
    
    return 0;
}