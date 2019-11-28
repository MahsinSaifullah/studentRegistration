#include "Student.h"
#include "UGStudent.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;


UGStudent::UGStudent()
{
  fullStudyLength=3;
  yearlyFee=0;
  balance=0;
}

UGStudent::UGStudent(string modeOfStudy, int feePaid, int id, int yearOfStudy, string department, string fname, string lname, string address, string tuitionStatus):Student(id, yearOfStudy, feePaid, modeOfStudy, department, fname, lname, address, tuitionStatus)
{
  fullStudyLength = 3;

  if (tuitionStatus == "Home" || tuitionStatus == "EU") yearlyFee = 9000;
  else yearlyFee = 18000;

  if(yearOfStudy == 1) balance = yearlyFee - feePaid;
  else if(yearOfStudy == 2) balance = 2*yearlyFee - feePaid;
  else  balance = 3*yearlyFee - feePaid;

}


int UGStudent::getFullStudyLength()
{
  return fullStudyLength;
}

int UGStudent::getYearlyFee()
{
  return yearlyFee;
}


int UGStudent::getBalance()
{
  return balance;
}

void UGStudent::displayInfo()
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

void UGStudent::payFee(int fee)
{
  feePaid += fee;

  if(yearOfStudy == 1) balance = yearlyFee - feePaid;
  else if(yearOfStudy == 2) balance = 2*yearlyFee - feePaid;
  else  balance = 3*yearlyFee - feePaid;

}
