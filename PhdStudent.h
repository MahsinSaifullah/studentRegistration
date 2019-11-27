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
