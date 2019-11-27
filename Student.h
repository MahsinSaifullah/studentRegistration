#ifndef STUDENT_H
#define	STUDENT_H
#include<string>
#include<vector>
using namespace std;



class Student
{
public:
  Student();
  Student(int,int,string,string,string,string,string);
  int getID();
  int getYearOfStudy();
  string getDepartment();
  string getFname();
  string getLname();
  string getAddress();
  string getTuitionStat();
  void enrol(string, string);



protected:
   int id;
   int yearOfStudy;
   string department;
   string fname;
   string lname;
   string address;
   string tuitionStatus;
   vector<string> enrolledModuleCode;
   vector<string> enrolledModuleName;
};



#endif
