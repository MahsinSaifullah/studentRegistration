#include "Student.h"
#include "MScStudent.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;


MScStudent::MScStudent()
{
  fullStudyLength=1;
  yearlyFee=0;
  balance=0;
}

MScStudent::MScStudent(string modeOfStudy, int feePaid, int id, int yearOfStudy, string department, string fname, string lname, string address, string tuitionStatus):Student(id, yearOfStudy, feePaid, modeOfStudy, department, fname, lname, address, tuitionStatus)
{
  this->modeOfStudy = modeOfStudy;
  fullStudyLength = 1;

  if (tuitionStatus == "HOME" || tuitionStatus == "EU") yearlyFee = 10000;
  else yearlyFee = 20000;

  balance = yearlyFee - feePaid;


}


int MScStudent::getFullStudyLength()
{
  return fullStudyLength;
}

int MScStudent::getYearlyFee()
{
  return yearlyFee;
}

int MScStudent::getBalance()
{
  return balance;
}

void MScStudent::displayInfo()
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

void MScStudent::payFee(int fee)
{
  feePaid += fee;
  balance = yearlyFee - feePaid;
}
