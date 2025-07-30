#include <iostream>
#include<string>
using namespace std;

class teacher{
private:
  double salary;
public:
    // teacher(){
    //     dept="CSE";
    // }
    teacher(string n,string d,string s,double sa){
        name=n;
        dept=d;
        subject=s;
        salary=sa;
    }
    string name;
    string dept;
    string subject;

    teacher(teacher &t){
        this->name=t.name;
        this->subject=t.subject;
        this->dept=t.dept;
        this->salary=t.salary;
    }
  
    void changeDept(string newDept){
        dept=newDept;
    }
    
    void setsalary(double s){
        salary=s;
    }

    double getsalary(){
        return salary;
    }
    void getinfo(){
        cout<<name<<" "<<dept<<" "<<subject<<" "<<getsalary();
    }
};

class student{
    public:
    string name;
    double *CGPAptr;
    student(string name,double CGPA){
        CGPAptr =new double;
        this->name=name;
        *CGPAptr=CGPA;
    }
    student(student &s1){
        this->name=s1.name;
        this->CGPAptr=new double;
        *CGPAptr=*s1.CGPAptr;
    }
    void getInfo(){
        cout<<name<<" "<<*CGPAptr;
    }
    ~student(){
        delete CGPAptr;
    }
};

int main() {
    // teacher t1("AA","CSE","DBMS",10000);
    // teacher t2(t1);
    // t2.getinfo();
    // teacher t3(t2);
    // t3.getinfo();
    student s1("Rahul",9.0);
    student s2(s1);
    s1.getInfo();
    *(s2.CGPAptr)=9.2;
    s2.getInfo();
    return 0;
}