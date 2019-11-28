#include "Student.h"
#include "UGStudent.h"
#include "MScStudent.h"
#include "PhdStudent.h"
#include "Module.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;


// void AddStudentz


int main()
{
  string modeOfStudy,department,fname,lname,address,status;
  int id, fee, yearOfStudy;

  cout<<"Enter mode Of Study: "<<flush;
  cin>>modeOfStudy;
  cout<<endl;
  cout<<"Enter fee paid: "<<flush;
  cin>>fee;
  cout<<endl;
  cout<<"Enter id: "<<flush;
  cin>>id;
  cout<<endl;
  cout<<"Enter year Of Study: "<<flush;
  cin>>yearOfStudy;
  cout<<endl;
  cout<<"Enter department: "<<flush;
  cin>>department;
  cout<<endl;
  cout<<"Enter first name: "<<flush;
  cin>>fname;
  cout<<endl;
  cout<<"Enter last name: "<<flush;
  cin>>lname;
  cout<<endl;
  cout<<"Enter address: "<<flush;
  cin>>address;
  cout<<endl;
  cout<<"Enter status: "<<flush;
  cin>>status;
  cout<<endl;



  MScStudent mahsin(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
  Module oop("ECS7080","Intro to OOP", "Dr. Mustafa", "covers the basic concepts of OOP using C++");
  Module NLP("ECS7081","Natural Language Processing", "Dr. Julian", "processing natural language using machine learning concepts");
  Module FuncP("ECS7082","Functional Programming", "Dr. Paulo", "intro to functional programming concepts using haskell");
  Module SemiD("ECS7083","Semi-Structured Data", "Dr. Tony", "different ways of handling data that semi Structured");
  mahsin.enrol(oop.getModuleCode(), oop.getModuleName());
  mahsin.enrol(NLP.getModuleCode(), NLP.getModuleName());
  mahsin.enrol(FuncP.getModuleCode(), FuncP.getModuleName());
  mahsin.enrol(SemiD.getModuleCode(), SemiD.getModuleName());
  mahsin.displayInfo();

  return 0;
}
