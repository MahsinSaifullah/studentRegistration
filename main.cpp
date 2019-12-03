#include "Student.h"
#include "UGStudent.h"
#include "MScStudent.h"
#include "PhdStudent.h"
#include "Module.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;


void clearConsole()
{
  cout << "\x1B[2J\x1B[H";
}

void addStudent(vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  string modeOfStudy,department,fname,lname,address,status;
  int id, fee, yearOfStudy;

  cout<<"Enter id: "<<flush;
  cin>>id;
  cout<<endl;
  cout<<"Enter mode Of Study: "<<flush;
  cin>>modeOfStudy;
  cout<<endl;
  cout<<"Enter fee paid: "<<flush;
  cin>>fee;
  cout<<endl;
  cout<<"Enter Current Year Of Study: "<<flush;
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
  cin.ignore();
  getline(cin, address);
  cout<<endl;
  cout<<"Enter status: "<<flush;
  cin>>status;
  cout<<endl;

  if (modeOfStudy == "UG")
  {
    UGStudent u(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
    ug.push_back(u);
  }
  else if (modeOfStudy == "MSC")
  {
    MScStudent m(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
    msc.push_back(m);
  }
  else
  {
    PhdStudent p(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
    phd.push_back(p);
  }

 cout<<"Student added Successfully..."<<endl;
 cout<<endl;
}



void removeStudent(int id, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getID() == id)
    {
      ug.erase(ug.begin() + i);
      return;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getID() == id)
    {
      msc.erase(msc.begin() + i);
      return;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getID() == id)
    {
      phd.erase(phd.begin() + i);
      return;
    }
  }

  cout<<"Student with id: "<<id<<" was removed Successfully..."<<endl;
  cout<<endl;
}


Student* searchById (int id, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  Student *st;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getID() == id)
    {
      st= &ug[i];
      return st;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getID() == id)
    {
      st = &msc[i];
      return st;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getID() == id)
    {
      st = &phd[i];
      return st;
    }
  }

  cout<<"No Student with that id was found..."<<endl;
  cout<<endl;
  return st;

}



Student* searchByFirstName (string fname, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  Student *st;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getFname() == fname)
    {
      st = &ug[i];
      return st;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getFname() == fname)
    {
      st = &msc[i];
      return st;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getFname() == fname)
    {
      st= &phd[i];
      return st;
    }
  }

  cout<<"No Student with that first name was found..."<<endl;
  cout<<endl;
  return st;
}



Student* searchByLastName (string lname, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{

  Student *st;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getLname() == lname)
    {
      st = &ug[i];
      return st;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getLname() == lname)
    {
      st = &msc[i];
      return st;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getLname() == lname)
    {
      st= &phd[i];
      return st;
    }
  }

  cout<<"No Student with that last name was found"<<endl;
  cout<<endl;
  return st;
}



vector<Student*> searchByDepartment (string department, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  vector<Student*> st;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getDepartment() == department)
    {
      st.push_back(&ug[i]);
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getDepartment() == department)
    {
      st.push_back(&msc[i]);
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getDepartment() == department)
    {
      st.push_back(&phd[i]);
    }
  }

  return st;
}



vector<Student*> searchByStatus (string tuitionStatus, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{

  vector<Student*> st;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getTuitionStat() == tuitionStatus)
    {
      st.push_back(&ug[i]);
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getTuitionStat() == tuitionStatus)
    {
      st.push_back(&msc[i]);
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getTuitionStat() == tuitionStatus)
    {
      st.push_back(&phd[i]);
    }
  }

  return st;

}

void addModule(vector<Module> &module)
{
  string moduleCode, moduleName, moduleProfessor, moduleSummary;

  cout<<"Enter moduleCode: "<<flush;
  cin>>moduleCode;
  cout<<"Enter Module Name: "<<flush;
  cin.ignore();
  getline(cin, moduleName);
  cout<<endl;
  cout<<"Enter Module Professor: "<<flush;
  cin.ignore();
  getline(cin, moduleProfessor);
  cout<<endl;
  cout<<"Enter Module Summary: "<<flush;
  cin.ignore();
  getline(cin, moduleSummary);
  cout<<endl;

  Module m(moduleCode, moduleName, moduleProfessor, moduleSummary);
  module.push_back(m);
}

Module* searchModuleByCode(string moduleCode, vector<Module> &module)
{
  Module *m;

  for(int i=0; i<module.size(); i++)
  {
    if(module[i].getModuleCode() == moduleCode)
    {
      m = &module[i];
      break;
    }
  }

  return m;
}

void enrollToModule(int id, string moduleCode, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd, vector<Module> &module)
{
  Module *foundModule;
  Student *foundStudent;

  foundStudent = searchById(id, ug, msc, phd);
  foundModule = searchModuleByCode(moduleCode, module);

  foundStudent->enrol(foundModule->getModuleCode(), foundModule->getModuleName());
  foundModule->addStudent(*foundStudent);
}

void readStudentFromFile(string filePath, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  string line;
  string id, feePaid, yearOfStudy, modeOfStudy, department, fname, lname, address, status;
  ifstream myStream(filePath);

  if(myStream.is_open())
  {
    while(getline(myStream, line))
    {
      stringstream ss(line);
      getline(ss, id, ',');
      getline(ss, modeOfStudy, ',');
      getline(ss, feePaid, ',');
      getline(ss, yearOfStudy, ',');
      getline(ss, department, ',');
      getline(ss, fname, ',');
      getline(ss, lname, ',');
      getline(ss, address, ',');
      getline(ss, status, '\n');

      if (modeOfStudy == "UG")
      {
        UGStudent u(modeOfStudy, stoi(feePaid), stoi(id), stoi(yearOfStudy), department, fname, lname, address, status);
        ug.push_back(u);
      }
      else if (modeOfStudy == "MSC")
      {
        MScStudent m(modeOfStudy, stoi(feePaid), stoi(id), stoi(yearOfStudy), department, fname, lname, address, status);
        msc.push_back(m);
      }
      else
      {
        PhdStudent p(modeOfStudy, stoi(feePaid), stoi(id), stoi(yearOfStudy), department, fname, lname, address, status);
        phd.push_back(p);
      }

    }
  }

  myStream.close();
}

void readModuleFromFile(string filePath, vector<Module> &module)
{
  string line;
  string moduleCode,moduleName,moduleProfessor, moduleSummary;
  ifstream myStream(filePath);

  if(myStream.is_open())
  {
    while(getline(myStream, line))
    {
      stringstream ss(line);
      getline(ss, moduleCode, ',');
      getline(ss, moduleName, ',');
      getline(ss, moduleProfessor, ',');
      getline(ss, moduleSummary, ',');

      Module m(moduleCode, moduleName, moduleProfessor, moduleSummary);
      module.push_back(m);
    }
  }

  myStream.close();
}

int main()
{
  vector<UGStudent> ug;
  vector<MScStudent> msc;
  vector<PhdStudent> phd;
  vector<Module> module;

  readStudentFromFile("student.csv", ug, msc, phd);
  readModuleFromFile("module.csv", module);

  enrollToModule(10,"ECS793P",ug,msc,phd,module);
  enrollToModule(10,"ECS769P",ug,msc,phd,module);
  Student* s = searchById(10,ug,msc,phd);
  s->displayInfo();






  return 0;
}
