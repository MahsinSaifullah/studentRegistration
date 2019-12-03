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

void Module::addStudent(Student s)
{
  studentsEnrolled.push_back(s);
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
  cout<<"ID\t\t\t\tFirst Name\t\t\tLast Name"<<endl;
  for(int i=0; i<studentsEnrolled.size(); i++)
  {
    cout<<studentsEnrolled[i].getID()<<"\t\t\t\t"<<studentsEnrolled[i].getFname()<<"\t\t\t"<<studentsEnrolled[i].getLname()<<endl;
  }
}
