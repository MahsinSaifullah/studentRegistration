#ifndef UGSTUDENT_H
#define	UGSTUDENT_H
#include "Student.h"
#include<string>
using namespace std;


class UGStudent: public Student
{
public:
  UGStudent();
  UGStudent(string, int, int,int,string,string,string,string,string);
  string getModeOfStudy();
  int getFullStudyLength();
  int getYearlyFee();
  int getFeePaid();
  int getBalance();
  void displayInfo();
  void payFee(int);


private:
  string modeOfStudy;
  int fullStudyLength;
  int yearlyFee;
  int feePaid;
  int balance;
};

#endif
