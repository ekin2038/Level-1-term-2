#include<iostream>
#include<cstring>
using namespace std;
class Batch;
class Student
{
    char *p;
    long long id;
    double credit;
    double cgpa;
public:
    Student(char*ptr, long long i, double c, double cg)
    {
        p=(char*)malloc(strlen(ptr)+1 );
        if(!p)
        {
            cout<<"Allocation error!"<<endl;
            exit(1);
        }
        strcpy(p, ptr);
        id= i;
        credit= c;
        cgpa= cg;
    }

    void change(char*ptr)
    {
        p= (char*)realloc(p, strlen(ptr)+1);
        if(!p)
        {
            cout<<"Allocation error!"<<endl;
            exit(1);
        }
        strcpy(p, ptr);
    }

    ~Student()
    {
        //cout<<"Freeing p.."<<endl;
        free(p);
    }
    void showInfo()
    {
        cout<<"Name: "<<p<<",  " <<"Id: "<<id<<",  "<<"Credit Completed: "<<credit<<",  "<<"Cgpa: "<<cgpa<<endl;
    }
    void change(long long n)
    {
        id= n;
    }
    void addTermResult(double c, double cg)
    {
        cgpa= c*cg + credit* cgpa;
        credit= credit+ c;
        cgpa = cgpa/ credit;
    }
    friend class Batch;
};


class Batch
{
    Student *s;
    int count=0;
public:
    Batch()
    {
        s=(Student*)malloc(1200* sizeof(Student) );
        if(!s)
        {
            cout<<"Allocation error!"<<endl;
            exit(1);
        }
    }
    ~Batch()
    {
        //cout<<"Freeing s"<<endl;
        free(s);
    }
    void addStudent(Student &ob)
    {
        s[count]=ob;
        count++;
    }
    void showAllStudents()
    {
        for(int i=0; i<count; i++)
            cout<<"Name: "<<s[i].p<<",  " <<"Id: "<<s[i].id<<",  "<<"Credit Completed: "<<s[i].credit<<",  "<<"Cgpa: "<<s[i].cgpa<<endl;
    }
};


int main()
{
    Student s1("Tamim Iqbal", 1905131, 39, 3.56);
    Student s2("Liton Das", 1905150, 39, 3.52);
    s1.showInfo();
    cout<<"Changing the name of s1"<<endl;
    s1.change("Tamim Iqbal Khan");
    s1.showInfo();
    cout<<"Changing the id of s2"<<  endl;
    s2.change(1905149);
    s2.showInfo();

    cout<< "Adding a term result of s1"<<endl;
    s1.addTermResult(19, 3.85);
    s1.showInfo();

    Batch b;
    b.addStudent(s1);
    b.addStudent(s2);
    cout<<"Printing the list of students of the batch b"<<endl;
    b.showAllStudents();
    return 0;
}
