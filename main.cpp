#include "Student.h"
#include "UGStudent.h"
#include "MScStudent.h"
#include "PhdStudent.h"
#include "Module.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void addUGStudent(vector<UGStudent> &ug)
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
  UGStudent u(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
  ug.push_back(u);
}

void addMScStudent(vector<MScStudent> &msc)
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
  MScStudent m(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
  msc.push_back(m);
}

void addPhdStudent(vector<PhdStudent> &phd)
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
  PhdStudent p(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
  phd.push_back(p);
}

Student* searchById (int id, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  Student *stUG = new UGStudent;
  Student *stMSc = new MScStudent;
  Student *stPhd = new PhdStudent;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getID() == id)
    {
      stUG = &ug[i];
      return stUG;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getID() == id)
    {
      stMSc = &msc[i]
      return stMSc;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getID() == id)
    {
      stPhd = &phd[i];
      return stPhd;
    }
  }

  return stUG;

}

Student* searchByFirstName (string fname, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  Student *stUG = new UGStudent;
  Student *stMSc = new MScStudent;
  Student *stPhd = new PhdStudent;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getFname() == fname)
    {
      stUG = &ug[i];
      return stUG;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getFname() == fname)
    {
      stMSc = &msc[i]
      return stMSc;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getFname() == fname)
    {
      stPhd = &phd[i];
      return stPhd;
    }
  }

  return stUG;
}

Student* searchByLastName (string lname, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  Student *stUG = new UGStudent;
  Student *stMSc = new MScStudent;
  Student *stPhd = new PhdStudent;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getLname() == lname)
    {
      stUG = &ug[i];
      return stUG;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getLname() == lname)
    {
      stMSc = &msc[i]
      return stMSc;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getLname() == lname)
    {
      stPhd = &phd[i];
      return stPhd;
    }
  }

  return stUG;
}

vector<Student*> searchByDepartment (string department, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  vector<Student*> stUG = new vector<UGStudent>;
  vector<Student*> stMSc = new vector<MScStudent>;
  vector<Student*> stPhd = new vector<PhdStudent>;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getDepartment() == department)
    {
      stUG.push_back(&ug[i]);
      return stUG;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getDepartment() == department)
    {
      stMSc.push_back(&msc[i]);
      return stMSc;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getDepartment() == department)
    {
      stPhd.push_back(&phd[i]);
      return stPhd;
    }
  }

  return stUG;
}

vector<Student*> searchByStatus (string tuitionStatus, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  vector<Student*> stUG = new vector<UGStudent>;
  vector<Student*> stMSc = new vector<MScStudent>;
  vector<Student*> stPhd = new vector<PhdStudent>;

  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getTuitionStat() == tuitionStatus)
    {
      stUG.push_back(&ug[i]);
      return stUG;
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getTuitionStat() == tuitionStatus)
    {
      stMSc.push_back(&msc[i]);
      return stMSc;
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getTuitionStat() == tuitionStatus)
    {
      stPhd.push_back(&phd[i]);
      return stPhd;
    }
  }

  return stUG;
}


int main()
{
  vector<UGStudent> ug;
  vector<MScStudent> msc;
  vector<PhdStudent> phd;
  vector<Module> module;

  addMScStudent(msc);
  addUGStudent(ug);
  addUGStudent(ug);
  addPhdStudent(phd);

  searchById()

  for(int i=0; i<msc.size();i++) msc[i].displayInfo();
  cout<<endl;
  cout<<endl;



  return 0;
}
