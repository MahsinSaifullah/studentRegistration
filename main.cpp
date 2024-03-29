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
#include<algorithm>

using namespace std;


void clearConsole()
{
  cout << "\033[2J\033[1;1H";;
}

void toUpperCase(string &mystring)
{
  transform(mystring.begin(), mystring.end(), mystring.begin(), ::toupper);
}



Student* searchById (int id, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{


  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getID() == id)
    {
      return &ug[i];
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getID() == id)
    {
      return &msc[i];
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getID() == id)
    {
      return &phd[i];
    }
  }



  Student st;
  Student *stPointer = new Student;
  *stPointer = st;

  return stPointer;

}



Student* searchByFirstName (string fname, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{


  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getFname() == fname)
    {
      return &ug[i];
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getFname() == fname)
    {
      return &msc[i];
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getFname() == fname)
    {
      return &phd[i];
    }
  }

  Student st;
  Student *stPointer = new Student;
  *stPointer = st;

  return stPointer;
}



Student* searchByLastName (string lname, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{



  for(int i=0; i<ug.size(); i++)
  {
    if(ug[i].getLname() == lname)
    {
      return &ug[i];
    }
  }

  for(int i=0; i<msc.size(); i++)
  {
    if(msc[i].getLname() == lname)
    {
      return &msc[i];
    }
  }

  for(int i=0; i<phd.size(); i++)
  {
    if(phd[i].getLname() == lname)
    {
      return &phd[i];
    }
  }

  Student st;
  Student *stPointer = new Student;
  *stPointer = st;

  return stPointer;
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

void addStudent(vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd)
{
  string modeOfStudy,department,fname,lname,address,status;
  int id, fee, yearOfStudy;
  string input;

  clearConsole();
  cout<<"--------------Follow the instructions to add a student------------------"<<endl;
  cout<<endl;
  do {
    cout<<endl;
    cout<<"Enter id: "<<flush;
    cin>>input;
    try{
      id = stoi (input);
    }catch (exception e) {
      cout<< "Invalid entry. Please try again!!!!"<<endl;
      id=0;
      continue;
    }
    Student *st = searchById(id, ug, msc, phd);
    if(st->getID()==0)
    {
      delete st;
    }
    else
    {
      cout<<"A student with that id already exist. Please enter a different id"<<endl;
      id = 0;
    }
  } while(id == 0);

  cout<<endl;
  do {
    cout<<"Enter mode Of Study (UG, MSC or PHD): "<<flush;
    cin>>modeOfStudy;
    toUpperCase(modeOfStudy);
    cout<<endl;
    if (modeOfStudy != "UG" && modeOfStudy != "MSC" && modeOfStudy != "PHD")
    {
      cout<<"Invalid entry. Please Try again...."<<endl;
      modeOfStudy = "";
      cout<<endl;
    }
  } while(modeOfStudy == "");

  do {
    cout<<"Enter fee paid: "<<flush;
    cin>>input;
    try{
      fee = stoi (input);
    }catch (exception e) {
      cout<< "Invalid entry. Please try again!!!!"<<endl;
      fee=0;
    }
    cout<<endl;
  } while(fee==0);

  do {
    cout<<"Enter Current Year Of Study: "<<flush;
    cin>>input;
    try{
      yearOfStudy = stoi (input);
    }catch (exception e) {
      cout<< "Invalid entry. Please try again!!!!"<<endl;
      yearOfStudy=0;
    }
    cout<<endl;
  } while(yearOfStudy==0);

  do {
    cout<<"Enter department (CS, MATH or EE): "<<flush;
    cin>>department;
    toUpperCase(department);
    cout<<endl;
    if (department != "CS" && department != "MATH" && department != "EE")
    {
      cout<<"There is no such department. Please Try again...."<<endl;
      department = "";
      cout<<endl;
    }
  } while(department == "");

  cout<<"Enter first name: "<<flush;
  cin>>fname;
  toUpperCase(fname);
  cout<<endl;
  cout<<"Enter last name: "<<flush;
  cin>>lname;
  toUpperCase(lname);
  cout<<endl;
  cout<<"Enter address: "<<flush;
  cin.ignore();
  getline(cin, address);
  cout<<endl;
  do {
    cout<<"Enter status (HOME, EU or INTERNATIONAL): "<<flush;
    cin>>status;
    toUpperCase(status);
    cout<<endl;
    if (status != "HOME" && status != "EU" && status != "INTERNATIONAL")
    {
      cout<<"Invalid entry. Please Try again...."<<endl;
      status = "";
      cout<<endl;
    }
  } while(status == "");


  if (modeOfStudy == "UG")
  {
    UGStudent u(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
    ug.push_back(u);
    cout<<"Student added Successfully..."<<endl;
    cout<<endl;
    u.displayInfo();
  }
  else if (modeOfStudy == "MSC")
  {
    MScStudent m(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
    msc.push_back(m);
    cout<<"Student added Successfully..."<<endl;
    cout<<endl;
    m.displayInfo();
  }
  else
  {
    PhdStudent p(modeOfStudy, fee, id, yearOfStudy, department, fname, lname, address, status);
    phd.push_back(p);
    cout<<"Student added Successfully..."<<endl;
    cout<<endl;
    p.displayInfo();
  }


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


}

void addModule(vector<Module> &module)
{
  string moduleCode, moduleName, moduleProfessor, moduleSummary;

  cout<<"Enter moduleCode: "<<flush;
  cin>>moduleCode;
  toUpperCase(moduleCode);
  cout<<"Enter Module Name: "<<flush;
  cin.ignore();
  getline(cin, moduleName);
  toUpperCase(moduleName);
  cout<<endl;
  cout<<"Enter Module Professor: "<<flush;
  cin.ignore();
  getline(cin, moduleProfessor);
  toUpperCase(moduleProfessor);
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


  for(int i=0; i<module.size(); i++)
  {
    if(module[i].getModuleCode() == moduleCode)
    {
      return &module[i];
    }
  }

  Module m("","","","");
  Module *mPointer = new Module;
  *mPointer = m;
  return mPointer;
}

void enrollToModule(int id, string moduleCode, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd, vector<Module> &module)
{
  Module *foundModule;
  Student *foundStudent;
  bool alreadyEnrolled = false;

  foundStudent = searchById(id, ug, msc, phd);
  foundModule = searchModuleByCode(moduleCode, module);
  vector<int> studentID = foundModule->getStudentID();

  for(int i=0; i<studentID.size();i++)
  {
    if (studentID[i] == id)
    {
      alreadyEnrolled = true;
      break;
    }
  }

  if(alreadyEnrolled) cout<<"The student with id: "<<id<< " is already enrolled to the module: "<<moduleCode<<endl;
  else
  {
    foundStudent->enrol(foundModule->getModuleCode(), foundModule->getModuleName());
    foundModule->addStudent(*foundStudent);
  }

}

void removeModule(string moduleCode, vector<Module> &module)
{
  for(int i=0; i<module.size(); i++)
  {
    if(module[i].getModuleCode() == moduleCode)
    {
      module.erase(module.begin() + i);
      return;
    }
  }

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

void readEnrollmentInfoFromFile(string filePath, vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd, vector<Module> &module)
{
  string line;
  string moduleCode, id;
  vector<string> studentID;
  ifstream myStream(filePath);

  if(myStream.is_open())
  {
    while(getline(myStream, line))
    {
      stringstream ss(line);
      getline(ss, moduleCode, ',');
      for(int i=0; i<20; i++)
      {
        getline(ss, id, ',');
        studentID.push_back(id);
      }


      for(int i=0; i<studentID.size(); i++)
      {
        if(stoi(studentID[i]) != 0)
        {
          enrollToModule(stoi(studentID[i]),moduleCode,ug,msc,phd,module);
        }
      }

      studentID.clear();

    }
  }

  myStream.close();
}


void saveData(vector<UGStudent> &ug, vector<MScStudent> &msc, vector<PhdStudent> &phd, vector<Module> &module)
{
  string studentFile = "student.csv";
  string moduleFile = "module.csv";
  string enrollmentFile = "enrollment.csv";

  ofstream studentStream(studentFile);
  ofstream moduleStream(moduleFile);
  ofstream enrollmentStream(enrollmentFile);

  if(studentStream.is_open())
  {
    for(int i=0; i<ug.size(); i++)
    {
      studentStream<<ug[i].getID()<<","<<ug[i].getModeOfStudy()<<","
      <<ug[i].getFeePaid()<<","<<ug[i].getYearOfStudy()<<","<<ug[i].getDepartment()<<","
      <<ug[i].getFname()<<","<<ug[i].getLname()<<","<<ug[i].getAddress()<<","<<ug[i].getTuitionStat()<<endl;
    }

    for(int i=0; i<msc.size(); i++)
    {
      studentStream<<msc[i].getID()<<","<<msc[i].getModeOfStudy()<<","
      <<msc[i].getFeePaid()<<","<<msc[i].getYearOfStudy()<<","<<msc[i].getDepartment()<<","
      <<msc[i].getFname()<<","<<msc[i].getLname()<<","<<msc[i].getAddress()<<","<<msc[i].getTuitionStat()<<endl;
    }

    for(int i=0; i<phd.size(); i++)
    {
      studentStream<<phd[i].getID()<<","<<phd[i].getModeOfStudy()<<","
      <<phd[i].getFeePaid()<<","<<phd[i].getYearOfStudy()<<","<<phd[i].getDepartment()<<","
      <<phd[i].getFname()<<","<<phd[i].getLname()<<","<<phd[i].getAddress()<<","<<phd[i].getTuitionStat()<<endl;
    }

  }

  if(moduleStream.is_open())
  {
    for(int i=0; i<module.size(); i++)
    {
      moduleStream<<module[i].getModuleCode()<<","<<module[i].getModuleName()<<","
      <<module[i].getModuleProfessor()<<","<<module[i].getModuleSummary()<<endl;
    }

  }

  if(enrollmentStream.is_open())
  {
    int zero = 0;
    vector<int> studentID;

    for(int i=0; i<module.size(); i++)
    {
      studentID = module[i].getStudentID();
      enrollmentStream<<module[i].getModuleCode()<<",";

      for (int j=0;j<20;j++)
      {
        if(j < studentID.size())
        {
          enrollmentStream<<studentID[j]<<",";
        }
        else
        {
          if(j!=19) enrollmentStream<<zero<<",";
          else enrollmentStream<<zero;
        }
      }

      enrollmentStream<<endl;
      studentID.clear();

    }

  }

  studentStream.close();
  moduleStream.close();
  enrollmentStream.close();

}

int main()
{
  vector<UGStudent> ug;
  vector<MScStudent> msc;
  vector<PhdStudent> phd;
  vector<Module> module;

  readStudentFromFile("student.csv", ug, msc, phd);
  readModuleFromFile("module.csv", module);
  readEnrollmentInfoFromFile("enrollment.csv", ug, msc, phd, module);


  string option;
  string input;

  clearConsole();

do {
  cout<<"***********************************************************************"<<endl;
  cout<<"*                 <-----STUDENT REGISTRATION----->                    *"<<endl;
  cout<<"*                      ----------------------                         *"<<endl;
  cout<<"***********************************************************************"<<endl;
  cout<<endl;
  cout<<"--------------Choose an option from the following menu------------------"<<endl;
  cout<<endl;
  cout<<"Press 1 : Add a Student"<<endl;
  cout<<"Press 2 : Enrol a Student to Modules"<<endl;
  cout<<"Press 3 : Remove a Student"<<endl;
  cout<<"Press 4 : Search a Student by Id"<<endl;
  cout<<"Press 5 : Search a Student by First Name"<<endl;
  cout<<"Press 6 : Search a Student by Last Name"<<endl;
  cout<<"Press 7 : Search Students by Department"<<endl;
  cout<<"Press 8 : Display all Student"<<endl;
  cout<<"Press 9 : Add a new module"<<endl;
  cout<<"Press 10 : Display all module"<<endl;
  cout<<"Press 11 : Remove a module"<<endl;
  cout<<"Press 0 : Save and exit"<<endl;
  cin>>option;

  if (option == "1")
  {
    addStudent(ug, msc, phd);
    cout<<endl;
    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();

  }
  else if(option == "2")
  {
    int allowedNumberOfModules;
    int id;
    Student *st;

    do {
      cout<<"---------------------------------------------------"<<endl;
      cout<<"Enter the id of the student to be enrolled: "<<flush;
      cin>>input;
      try{
        id = stoi(input);
      }catch(exception e){
        cout<<"Invalid entry. Please try again !!!"<<endl;
        cout<<endl;
        id = 0;
        continue;
      }

      st = searchById(id, ug, msc, phd);

      if (st->getID() == 0)
      {
        cout<<"Student with id: "<<id<<" is not in the system. Please try again!!!"<<endl;
        cout<<endl;
        id=0;
        delete st;
      }

      else
      {
        vector<string> moduleCode = st->getEnrolledModuleCode();
        if (st->getModeOfStudy()=="UG" && moduleCode.empty()) allowedNumberOfModules = 4;
        else if (st->getModeOfStudy()=="MSC" && moduleCode.empty()) allowedNumberOfModules = 3;
        else if (st->getModeOfStudy()=="PHD" && moduleCode.empty())
        {
          cout<<"The student with this id is a phd student. Phd student can choose the total number of modules to enroll"<<endl;
          do {
            cout<<endl;
            cout<<"Enter the total number of modules to enroll: "<<flush;
            cin>>input;
            try{
              allowedNumberOfModules = stoi(input);
            }catch(exception e){
              cout<<"Invalid entry. Please try again !!!"<<endl;
              cout<<endl;
              allowedNumberOfModules = 0;
            }
          } while(allowedNumberOfModules == 0);
          cin>>allowedNumberOfModules;
        }
        else
        {
          allowedNumberOfModules = 0;
        }
      }
    } while(id == 0);

    cout<<endl;

    if(allowedNumberOfModules == 0)
    {
      cout<<"The Student already enrolled to the maximum number of modules allowed"<<endl;
      cout<<endl;
      do {
        cout<<"-----------------------------------------"<<endl;
        cout<<"Press 1 : To return to the main menu"<<endl;
        cout<<"Press 0 : Save and exit"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cin>>option;
        if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

      } while(option != "1" && option != "0");

      clearConsole();
    }
    else
    {
      clearConsole();

      do {
        int moduleIndex;
        int moduleOption;
        cout<<"--------------------------------------------------------------------------"<<endl;
        cout<<"The following modules are available"<<endl;
        cout<<"Choose an option to learn the details of the module and to enroll to them"<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<st->getModeOfStudy()<<" student..."<<endl;
        cout<<"The Student can enroll to "<<allowedNumberOfModules<<" more modules"<<endl;
        for(int i=0; i<module.size(); i++)
        {
          cout<<"Press "<< i <<": "<<module[i].getModuleCode()<<endl;
        }

        cout<<endl;
        cin>>input;

        try{
          moduleIndex = stoi(input);
        }catch(exception e){
          cout<<endl;
          cout<<"Invalid Entry. Please Try again !!!"<<endl;
          cout<<endl;
          continue;
        }

        if (moduleIndex >= module.size()) cout<<"Invalid Choice. Try again !!!"<<endl;
        else
        {
          clearConsole();
          vector<int> studentID = module[moduleIndex].getStudentID();
          module[moduleIndex].displayModule();
          cout<<endl;
          cout<<endl;
          cout<<"-----------------------------------------"<<endl;
          cout<<"Press 1 : To enroll to this module"<<endl;
          cout<<"Press 0 : To keep looking"<<endl;
          cout<<"-----------------------------------------"<<endl;
          cin>>moduleOption;

          if(moduleOption == 1 && find(studentID.begin(), studentID.end(), id) == studentID.end())
          {
            enrollToModule(id, module[moduleIndex].getModuleCode(), ug, msc, phd, module);
            allowedNumberOfModules--;
          }
          else if(moduleOption == 1 && find(studentID.begin(), studentID.end(), id) != studentID.end())
          {
            cout<<"The student already enrolled to this module"<<endl;
            cout<<"Please try again"<<endl;
            cout<<endl;
          }

        }
      } while(allowedNumberOfModules != 0);

      clearConsole();

      cout<<"The Student enrolled to the maximum number of allowed modules"<<endl;
      cout<<endl;

      do {
        cout<<"-----------------------------------------"<<endl;
        cout<<"Press 1 : To return to the main menu"<<endl;
        cout<<"Press 0 : Save and exit"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cin>>option;
        if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

      } while(option != "1" && option != "0");

      clearConsole();

    }

  }
  else if (option == "3")
  {
    int id;
    Student *st;

    do {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter the id of the student to be removed: "<<flush;
        cin>>input;
        cout<<endl;
        try{
          id = stoi(input);
        }catch(exception e){
          cout<<"Invalid entry. Please try again!!!"<<endl;
          cout<<endl;
          id=0;
          continue;
        }
        st = searchById(id, ug, msc, phd);

        if (st->getID() == 0)
        {
          cout<<"Student with id: "<<id<<" is not in the system. Please try again!!!"<<endl;
          cout<<endl;
          id=0;
          delete st;
        }
    }while(id == 0);

    cout<<endl;
    do {
      cout<<"You sure you want to remove Student with id: "<<id<<" (y/n)"<<endl;
      cin>>input;
      toUpperCase(input);
      if (input == "Y")
      {
        clearConsole();
        removeStudent(id, ug, msc, phd);
        cout<<endl;
        cout<<"Student with id: "<<id<<" was removed Successfully..."<<endl;
        cout<<endl;
        do {
          cout<<"-----------------------------------------"<<endl;
          cout<<"Press 1 : To return to the main menu"<<endl;
          cout<<"Press 0 : Save and exit"<<endl;
          cout<<"-----------------------------------------"<<endl;
          cin>>option;
          if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

        } while(option != "1" && option != "0");
      }
      else if(input == "N")
      {
        do {
          cout<<"-----------------------------------------"<<endl;
          cout<<"Press 1 : To return to the main menu"<<endl;
          cout<<"Press 0 : Save and exit"<<endl;
          cout<<"-----------------------------------------"<<endl;
          cin>>option;
          if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

        } while(option != "1" && option != "0");
      }
      else{
        cout<<"Invalid entry. Please try again!!!"<<endl;
        cout<<endl;
      }
    } while(input != "Y" && input != "N");

    clearConsole();

  }

  else if(option == "4")
  {
    int id;
    Student *st;

    do {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter the id of the student to be searched: "<<flush;
        cin>>input;
        cout<<endl;
        try{
          id = stoi(input);
        }catch(exception e){
          cout<<"Invalid entry. Please try again!!!"<<endl;
          cout<<endl;
          id=0;
          continue;
        }
        st = searchById(id, ug, msc, phd);

        if (st->getID() == 0)
        {
          cout<<"Student with id: "<<id<<" is not in the system. Please try again!!!"<<endl;
          cout<<endl;
          id=0;
          delete st;
        }
    }while(id == 0);

    clearConsole();

    cout<<"-----------------------------------------"<<endl;
    st->displayInfo();
    cout<<"-----------------------------------------"<<endl;

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();
  }

  else if(option == "5")
  {
    string fname;
    Student *st;

    do {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter the first name of the student to be searched: "<<flush;
        cin>>fname;
        toUpperCase(fname);
        cout<<endl;
        st = searchByFirstName(fname, ug, msc, phd);

        if (st->getFname() == "")
        {
          cout<<"Student with first name: "<<fname<<" is not in the system. Please try again!!!"<<endl;
          cout<<endl;
          fname="";
          delete st;
        }
    }while(fname=="");

    clearConsole();

    cout<<"-----------------------------------------"<<endl;
    st->displayInfo();
    cout<<"-----------------------------------------"<<endl;

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

     clearConsole();
  }

  else if(option == "6")
  {
    string lname;
    Student *st;

    do {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter the last name of the student to be searched: "<<flush;
        cin>>lname;
        toUpperCase(lname);
        cout<<endl;
        st = searchByLastName(lname, ug, msc, phd);

        if (st->getLname() == "")
        {
          cout<<"Student with last name: "<<lname<<" is not in the system. Please try again!!!"<<endl;
          cout<<endl;
          lname="";
          delete st;
        }
    }while(lname=="");

    cout<<"-----------------------------------------"<<endl;
    st->displayInfo();
    cout<<"-----------------------------------------"<<endl;

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();

  }

  else if(option == "7")
  {
    string departmentChoice;
    vector<Student*> st;

    clearConsole();

    do {
      cout<<"--------------Choose a Department to search by------------------"<<endl;
      cout<<endl;
      cout<<"Press 1 : CS"<<endl;
      cout<<"Press 2 : MATH"<<endl;
      cout<<"Press 3 : EE"<<endl;
      cin>>departmentChoice;

      if (departmentChoice == "1") st = searchByDepartment("CS",ug,msc,phd);
      else if (departmentChoice == "2") st = searchByDepartment("MATH",ug,msc,phd);
      else if (departmentChoice == "3") st = searchByDepartment("EE",ug,msc,phd);
      else
      {
        cout<<endl;
        cout<<"Invalid Choice. Please Try Again...."<<endl;
        cout<<endl;
        departmentChoice = "";
      }
    } while(departmentChoice == "");

    clearConsole();

    for (int i = 0; i<st.size(); i++)
    {
      cout<<"-----------------------------------------"<<endl;
      st[i]->displayInfo();
      cout<<"-----------------------------------------"<<endl;
    }

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();

  }

  else if(option == "8")
  {
    clearConsole();
    for(int i = 0; i<ug.size(); i++)
    {
      cout<<"---------------------------------------------"<<endl;
      ug[i].displayInfo();
      cout<<"---------------------------------------------"<<endl;
      cout<<endl;
    }
    for(int i = 0; i<msc.size(); i++)
    {
      cout<<"---------------------------------------------"<<endl;
      msc[i].displayInfo();
      cout<<"---------------------------------------------"<<endl;
      cout<<endl;
    }
    for(int i = 0; i<phd.size(); i++)
    {
      cout<<"---------------------------------------------"<<endl;
      phd[i].displayInfo();
      cout<<"---------------------------------------------"<<endl;
      cout<<endl;
    }

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();
  }

  else if(option == "9")
  {
    clearConsole();
    addModule(module);
    cout<<"A new Module Successfully added.."<<endl;
    cout<<endl;

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();

  }

  else if(option == "10")
  {
    clearConsole();
    for(int i = 0; i<module.size(); i++)
    {
      cout<<"---------------------------------------------"<<endl;
      module[i].displayModule();
      cout<<"---------------------------------------------"<<endl;
      cout<<endl;
    }

    do {
      cout<<"-----------------------------------------"<<endl;
      cout<<"Press 1 : To return to the main menu"<<endl;
      cout<<"Press 0 : Save and exit"<<endl;
      cout<<"-----------------------------------------"<<endl;
      cin>>option;
      if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

    } while(option != "1" && option != "0");

    clearConsole();

  }

  else if(option=="11")
  {
    string moduleCode;
    Module *foundModule;

    do {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Enter the Code of the module to be removed: "<<flush;
        cin>>moduleCode;
        toUpperCase(moduleCode);
        cout<<endl;
        foundModule = searchModuleByCode(moduleCode, module);

        if (foundModule->getModuleCode() == "")
        {
          cout<<"Module with code: "<<moduleCode<<" is not in the system. Please try again!!!"<<endl;
          cout<<endl;
          moduleCode="";
          delete foundModule;
        }
    }while(moduleCode == "");

    cout<<endl;
    do {
      cout<<"You sure you want to remove Module with code: "<<moduleCode<<" (y/n)"<<endl;
      cin>>input;
      toUpperCase(input);
      if (input == "Y")
      {
        clearConsole();
        removeModule(moduleCode, module);
        cout<<endl;
        cout<<"Module with Code: "<<moduleCode<<" was removed Successfully..."<<endl;
        cout<<endl;
        do {
          cout<<"-----------------------------------------"<<endl;
          cout<<"Press 1 : To return to the main menu"<<endl;
          cout<<"Press 0 : Save and exit"<<endl;
          cout<<"-----------------------------------------"<<endl;
          cin>>option;
          if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

        } while(option != "1" && option != "0");
      }
      else if(input == "N")
      {
        do {
          cout<<"-----------------------------------------"<<endl;
          cout<<"Press 1 : To return to the main menu"<<endl;
          cout<<"Press 0 : Save and exit"<<endl;
          cout<<"-----------------------------------------"<<endl;
          cin>>option;
          if(option != "1" && option != "0") cout<<"Invalid Choice. Try again !!!"<<endl;

        } while(option != "1" && option != "0");
      }
      else{
        cout<<"Invalid entry. Please try again!!!"<<endl;
        cout<<endl;
      }
    } while(input != "Y" && input != "N");

    clearConsole();

  }

  else if(option == "0")
  {
    clearConsole();
    cout<<endl;
    cout<<"Thanks for using the System"<<endl;
    cout<<endl;
  }



  else
  {
    cout<<endl;
    cout<<"Invalid Choice..Please try Again!!!!"<<endl;
    cout<<endl;
  }


} while(option != "0");


  saveData(ug, msc, phd, module);
  cout<<"All data Successfully saved..."<<endl;
  cout<<endl;



  return 0;
}
