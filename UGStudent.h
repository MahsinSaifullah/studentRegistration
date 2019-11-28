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
  int getFullStudyLength();
  int getYearlyFee();
  int getBalance();
  void displayInfo();
  void payFee(int);


private:
  int fullStudyLength;
  int yearlyFee;
  int balance;
};

#endif
