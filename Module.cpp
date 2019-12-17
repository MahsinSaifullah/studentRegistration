#include "Module.h"
#include "Student.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

Module::Module()
{
  moduleCode = "";
  moduleName = "";
  moduleProfessor = "";
  moduleSummary = "";
}
Module::Module(string moduleCode, string moduleName, string moduleProfessor, string moduleSummary)
{
  this->moduleCode = moduleCode;
  this->moduleName = moduleName;
  this->moduleProfessor = moduleProfessor;
  this->moduleSummary = moduleSummary;
}

string Module::getModuleCode()
{
  return moduleCode;
}

string Module::getModuleName()
{
  return moduleName;
}

string Module::getModuleProfessor()
{
  return moduleProfessor;
}

string Module::getModuleSummary()
{
  return moduleSummary;
}

vector<int> Module::getStudentID()
{
  return studentID;
}
vector<string> Module::getStudentFName()
{
  return studentFName;
}
vector<string> Module::getStudentLName()
{
  return studentLName;
}
vector<string> Module::getStudentDepartment()
{
  return studentDepartment;
}

void Module::addStudent(Student s)
{
  studentID.push_back(s.getID());
  studentFName.push_back(s.getFname());
  studentLName.push_back(s.getLname());
  studentDepartment.push_back(s.getDepartment());
}

void Module::displayModule()
{
  cout<<"Module Code: "<<moduleCode<<endl;
  cout<<"Module Name: "<<moduleName<<endl;
  cout<<"Module Professor: "<<moduleProfessor<<endl;
  cout<<"Module Summary: "<<moduleSummary<<endl;
  cout<<endl;
  cout<<"Students enrolled: "<<endl;
  cout<<endl;
  cout<<"ID\t\t\t\tFirst Name\t\tLast Name\t\t\tDepartment"<<endl;
  for(int i=0; i<studentID.size(); i++)
  {
    cout<<studentID[i]<<"\t\t\t\t"<<studentFName[i]<<"\t\t\t"<<studentLName[i]<<"\t\t\t\t"<<studentDepartment[i]<<endl;
  }
}
