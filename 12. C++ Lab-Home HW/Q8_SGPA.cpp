#include<iostream>
#include<fstream>
using namespace std;

class student
{
   int roll;
   float marks[8];
   float sgpa;
   int semester;
   char branch[15];
   int batch;
	
	public:
		void get()
		{
			cout<<"Enter roll number, semester, branch and batch: ";
			cin>>roll>>semester>>branch>>batch;
			cout<<"Enter marks in 8 subjects: ";
			for(int i=0;i<8;i++){
				cin>>marks[i];
			}
			
		}
		float returnsgpa()
		{
			int total=0;
			for(int i=0;i<8;i++){
				total=total+marks[i];
			}
			sgpa=total/80.0;
			
			return sgpa;
		}
		
		void editrec()
		{
			for (int i = 0; i < 8; i++)
			{
				cout << "\nEnter marks in 8 subjects" << i + 1 << " : ";
				cin >> marks[i];
            }
            
			returnsgpa();
		}
		
		int returnroll(){
            return roll;
        }
		
		char *returnbranch(){
		    return branch;
		}
		
		int returnbatch(){
            return batch;
        }
        
		int returnsem(){
            return semester;
        }
	
		void show()
		{
			cout<<"\nRoll No.: "<<roll<<"\nSemester: "<<semester<<"\nBranch: "<<branch<<"\nBatch: "<<batch<<endl;
			cout<<"SGPA: "<<sgpa<<endl;
		}
};

void show()
{
   student s2;
   fstream f;
   cout << "\nDISPLAY";
   f.open("stud.txt", ios::in);
   while (f.read((char *)&s2, sizeof(s2)))
   {
      s2.show();
   }
   f.close();
}

void entry()
{
   student s1;
   fstream f;
   f.open("stud.txt", ios::in | ios::out | ios::ate);
   if (!f)
   {
      f.close();
      f.open("stud.txt", ios::out);
      f.close();
      f.open("stud.txt", ios::in | ios::out | ios::ate);
   }
   while (f.read((char *)&s1, sizeof(s1)))
   {
   }
   f.clear();
   s1.get();
   s1.returnsgpa();
   f.write((char *)&s1, sizeof(s1));
   f.close();
   show();
}

void edit()
{
   int erno;
   int flag = 0;
   cout << "\nEnter roll of entry to be edited: ";
   cin >> erno;
   student s;
   fstream f;
   f.open("stud.txt", ios::in | ios::out | ios::ate);
   f.seekg(0, ios::beg);
   while (f.read((char *)&s, sizeof(s)))
   {
      if (s.returnroll() == erno)
      {
         cout << "\nEntry found: ";
         s.show();
         break;
      }
   }
   
   s.editrec();
   cout << "\nEdited details: ";
   s.show();
   int size = sizeof(s);
   f.seekp(-size, ios::cur);
   f.write((char *)&s, sizeof(s));
   f.close();
   show();
}

void delrec()
{
   fstream f1, f2;
   int nroll;
   cout << "\nEnter roll of the entry to be deleted: ";
   cin >> nroll;
   f1.open("stud.txt", ios::in | ios::out | ios::ate);
   f2.open("temp.txt", ios::out);
   f1.seekg(0, ios::beg);
   f2.seekp(0, ios::beg);
   student s;
   while (f1.read((char *)&s, sizeof(s)))
   {
      if (nroll != s.returnroll())
      {
         f2.write((char *)&s, sizeof(s));
      }
      else
      {
         cout << "\nEntry to be deleted found.";
         s.show();
      }
   }
   f1.close();
   f2.close();
   remove("stud.txt");
   rename("temp.txt", "stud.txt");
   show();
}

void batchsort()
{
   student s1;
   fstream f;
   f.open("stud.txt", ios::in | ios::out | ios::ate);
   if (!f)
   {
      f.close();
      f.open("stud.txt", ios::out);
      f.close();
      f.open("stud.txt", ios::in | ios::out | ios::ate);
   }
   f.seekg(0, ios::beg);
   while (f.read((char *)&s1, sizeof(s1)))
   {
   }
   f.clear();
   int location = f.tellg();
   cout << "\nLocation :" << location;
   int no_obj = location / sizeof(s1);
   cout << "\nNo. of entries : " << no_obj;
   
   student s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   student temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (s[j].returnbatch() > s[j + 1].returnbatch())
         {
            temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
         }
      }
   }
   f.clear();
   f.seekp(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.write((char *)&s[i], sizeof(s[i]));
   }
   f.close();
   cout << "\nBatch wise sort: \n";
   show();
}

void branchsort()
{
   student s1;
   fstream f;
   f.open("stud.txt", ios::in | ios::out | ios::ate);
   if (!f)
   {
      f.close();
      f.open("stud.txt", ios::out);
      f.close();
      f.open("stud.txt", ios::in | ios::out | ios::ate);
   }
   f.seekg(0, ios::beg);
   while (f.read((char *)&s1, sizeof(s1)))
   {
   }
   f.clear();
   int location = f.tellg();
   cout << "\nLocation :" << location;
   int no_obj = location / sizeof(s1);
   cout << "\nNo. of entries : " << no_obj;
   
   student s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   student temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (strcmp(s[j].returnbranch(), s[j + 1].returnbranch()) > 0)
         {
            temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
         }
      }
   }
   f.clear();
   f.seekp(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.write((char *)&s[i], sizeof(s[i]));
   }
   f.close();
   cout << "\nBranch wise sort: \n";
   show();
}

void semestersort()
{
   student s1;
   fstream f;
   f.open("stud.txt", ios::in | ios::out | ios::ate);
   if (!f)
   {
      f.close();
      f.open("stud.txt", ios::out);
      f.close();
      f.open("stud.txt", ios::in | ios::out | ios::ate);
   }
   f.seekg(0, ios::beg);
   while (f.read((char *)&s1, sizeof(s1)))
   {
   }
   f.clear();
   int location = f.tellg();
   cout << "\nLocation :" << location;
   int no_obj = location / sizeof(s1);
   cout << "\nNo. of entries : " << no_obj;
   // sorting
   student s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   student temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (s[j].returnsem() > s[j + 1].returnsem())
         {
            temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
         }
      }
   }
   f.clear();
   f.seekp(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.write((char *)&s[i], sizeof(s[i]));
   }
   f.close();
   cout << "\nSemester wise sort: \n";
   show();
}

void deleteall()
{
   remove("stud.txt");
}

int main()
{
   int ch = 1;
   while (ch != 0)
   {
      cout << "\nKIIT GRADING SYSTEM";
      cout << "\n1.New entry & sgpa\n2.edited entry & sgpa\n3.Delete entry\n4.Batch sort\n5.Branch sort\n6.Semester sort\n7.Display.\n8.Delete all\n0.Exit... ";
      cout << "\nEnter choice: ";
      cin >> ch;
      switch (ch)
      {
      case 1:
         entry();
         break;
      case 2:
         edit();
         break;
      case 3:
         delrec();
         break;
      case 4:
         batchsort();
         break;
      case 5:
         branchsort();
         break;
      case 6:
         semestersort();
         break;
      case 7:
         show();
         break;
      case 8:
         deleteall();
         break;
      }
   }
   return 0;
}
