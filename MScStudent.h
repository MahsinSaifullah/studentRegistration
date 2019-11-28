#ifndef MSCSTUDENT_H
#define	MSCSTUDENT_H
#include "Student.h"
#include<string>
using namespace std;




class MScStudent: public Student
{
public:
  MScStudent();
  MScStudent(string, int, int,int,string,string,string,string,string);
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
