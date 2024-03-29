#ifndef STUDENT_H
#define	STUDENT_H
#include<string>
#include<vector>
using namespace std;



class Student
{
public:
  Student();
  Student(int,int,int,string,string,string,string,string,string);
  int getID();
  string getModeOfStudy();
  int getYearOfStudy();
  string getDepartment();
  string getFname();
  string getLname();
  string getAddress();
  string getTuitionStat();
  int getFeePaid();
  vector<string> getEnrolledModuleCode();
  vector<string> getEnrolledModuleName();
  void enrol(string, string);
  virtual void displayInfo();



protected:
   int id;
   string modeOfStudy;
   int yearOfStudy;
   string department;
   string fname;
   string lname;
   string address;
   string tuitionStatus;
   int feePaid;
   vector<string> enrolledModuleCode;
   vector<string> enrolledModuleName;
};



#endif
