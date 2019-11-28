#include "Student.h"
#include "PhdStudent.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;


PhdStudent::PhdStudent()
{

  fullStudyLength=4;
  yearlyFee=0;
  balance=0;
}

PhdStudent::PhdStudent(string modeOfStudy, int feePaid, int id, int yearOfStudy, string department, string fname, string lname, string address, string tuitionStatus):Student(id, yearOfStudy, feePaid, modeOfStudy, department, fname, lname, address, tuitionStatus)
{
  this->modeOfStudy = modeOfStudy;
  fullStudyLength = 3;

  if (tuitionStatus == "Home" || tuitionStatus == "EU") yearlyFee = 12000;
  else yearlyFee = 24000;

  if(yearOfStudy == 1) balance = yearlyFee - feePaid;
  else if(yearOfStudy == 2) balance = 2*yearlyFee - feePaid;
  else if(yearOfStudy == 3)  balance = 3*yearlyFee - feePaid;
  else balance = 4*yearlyFee - feePaid;

}


int PhdStudent::getFullStudyLength()
{
  return fullStudyLength;
}

int PhdStudent::getYearlyFee()
{
  return yearlyFee;
}


int PhdStudent::getBalance()
{
  return balance;
}

void PhdStudent::displayInfo()
{
  cout<<"ID: "<<id<<endl<<"First Name: "<<fname<<endl<<"Last Name: "<<lname<<endl;
  cout<<"Mode of Study: "<<modeOfStudy<<endl<<"Department: "<<department<<endl;
  cout<<"Status: "<< tuitionStatus<<endl<<"Current Year: "<<yearOfStudy<<endl;
  cout<<"Yearly fee: "<<yearlyFee<<endl<<"Total Fee Paid: "<<feePaid<<endl<<"Yearly Fee left: "<<balance<<endl;
  cout<<endl;
  cout<<"Enrolled Modules: "<<endl;
  cout<<endl;
  cout<<"Module Code\t\t\t\tModule Name"<<endl;
  cout<<endl;

  for(int i=0; i<enrolledModuleCode.size(); i++)
  {
    cout<<enrolledModuleCode[i]<<"\t\t\t\t"<<enrolledModuleName[i]<<endl;
  }
}

void PhdStudent::payFee(int fee)
{
  feePaid += fee;

  if(yearOfStudy == 1) balance = yearlyFee - feePaid;
  else if(yearOfStudy == 2) balance = 2*yearlyFee - feePaid;
  else if(yearOfStudy == 3)  balance = 3*yearlyFee - feePaid;
  else balance = 4*yearlyFee - feePaid;

}
