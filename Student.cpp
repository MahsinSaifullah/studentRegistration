#include "Student.h"
#include<string>
#include<vector>


Student::Student()
{
  id = 0;
  department = "";
  fname = "";
  lname = "";
  address = "";
  tuitionStatus = "";
}

Student::Student(int x, int yearOfStudy, string department, string fname, string lname, string address, string tuitionStatus)
{
  this->id = id;
  this->yearOfStudy = yearOfStudy;
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

void Student::enrol(string moduleCode, string moduleName)
{
  enrolledModuleCode.push_back(moduleCode);
  enrolledModuleName.push_back(moduleName);
}
