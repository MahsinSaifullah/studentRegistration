#ifndef MODULE_H
#define	MODULE_H
#include "Student.h"
#include<string>
#include<vector>
using namespace std;



class Module
{
public:
  Module();
  Module(string, string, string, string);
  string getModuleCode();
  string getModuleName();
  string getModuleProfessor();
  string getModuleSummary();
  vector<int> getStudentID();
  vector<string> getStudentFName();
  vector<string> getStudentLName();
  vector<string> getStudentDepartment();
  void addStudent(Student);
  void displayModule();

private:
  string moduleCode;
  string moduleName;
  string moduleProfessor;
  string moduleSummary;
  vector<int> studentID;
  vector<string> studentFName;
  vector<string> studentLName;
  vector<string> studentDepartment;
};



#endif
