#include "Student.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;


Student::Student()
{
  id = 0;
  modeOfStudy="";
  department = "";
  fname = "";
  lname = "";
  address = "";
  tuitionStatus = "";
  feePaid=0;
}

Student::Student(int id, int yearOfStudy, int feePaid, string modeOfStudy, string department, string fname, string lname, string address, string tuitionStatus)
{
  this->id = id;
  this->modeOfStudy = modeOfStudy;
  this->yearOfStudy = yearOfStudy;
  this->feePaid = feePaid;
  this->department = department;
  this->fname = fname;
  this->lname = lname;
  this->address = address;
  this->tuitionStatus = tuitionStatus;
}

int Student::getID()
{
  return id;
}

string Student::getModeOfStudy()
{
  return modeOfStudy;
}

int Student::getYearOfStudy()
{
  return yearOfStudy;
}

string Student::getDepartment()
{
  return department;
}

string Student::getFname()
{
  return fname;
}

string Student::getLname()
{
  return lname;
}

string Student::getAddress()
{
  return address;
}

string Student::getTuitionStat()
{
  return tuitionStatus;
}

int Student::getFeePaid()
{
  return feePaid;
}

vector<string> Student::getEnrolledModuleCode()
{
  return enrolledModuleCode;
}

vector<string> Student::getEnrolledModuleName()
{
  return enrolledModuleName;
}

void Student::enrol(string moduleCode, string moduleName)
{
  enrolledModuleCode.push_back(moduleCode);
  enrolledModuleName.push_back(moduleName);
}

void Student::displayInfo()
{
  cout<<"ID: "<<id<<endl<<"First Name: "<<fname<<endl<<"Last Name: "<<lname<<endl;
  cout<<"Mode of Study: "<<modeOfStudy<<endl<<"Department: "<<department<<endl;
  cout<<"Status: "<< tuitionStatus<<endl<<"Current Year: "<<yearOfStudy<<endl;
  cout<<"Total Fee Paid: "<<feePaid<<endl;
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
