#include "Student.h"
#include "UGStudent.h"
#include "MScStudent.h"
#include "PhdStudent.h"
#include "Module.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
  MScStudent mahsin("MSc", 18000, 1, 1, "Computer Science", "Mahsin", "Saifullah", "8 Boston Loft, Southend, SS2 6FR", "International");
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
