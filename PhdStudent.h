#ifndef PHDSTUDENT_H
#define	PHDSTUDENT_H
#include "Student.h"
#include<string>
using namespace std;


class PhdStudent: public Student
{
public:
  PhdStudent();
  PhdStudent(string, int, int,int,string,string,string,string,string);
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
