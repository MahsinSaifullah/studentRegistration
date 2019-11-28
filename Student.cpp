#include "Student.h"
#include<string>
#include<vector>


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

void Student::enrol(string moduleCode, string moduleName)
{
  enrolledModuleCode.push_back(moduleCode);
  enrolledModuleName.push_back(moduleName);
}
