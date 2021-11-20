#include <iostream>
#include <string>
#include <math.h>
#include "People.h"
#include "Mark.h"

class Student : public People, public Mark
{
private:
  string MSSV;
  string major;

public:
  Student();
  friend std::istream &operator>>(std::istream &is, Student &newStudent);
  friend std::ostream &operator<<(std::ostream &os, Student &newStudent);
  string getMSSV();
  string getMajor();
  void setMSSV(string newMSSV);
  void setMajor(string newMajor);
};

Student::Student()
{
}

std::istream &operator>>(std::istream &is, Student &newStudent)
{
  std::cout << std::endl
            << "\t**********Nhập thông tin**********" << std::endl
            << std::endl;
  std::cout << "\tNhập MSSV: ";
  is >> newStudent.MSSV;
  newStudent.Input();
  std::cout << "\tNhập ngành học: ";
  getline(is, newStudent.major);
  newStudent.Input2();
  std::cout << std::endl
            << "\t*************************" << std::endl;
  return is;
}

std::ostream &operator<<(std::ostream &os, Student &newStudent)
{
  os << "||" << newStudent.MSSV << "\t\t";
  newStudent.Output();
  os << "||" << newStudent.major << "\t\t";
  newStudent.OutPut2();
  return os;
}

string Student::getMSSV()
{
  return MSSV;
}

string Student::getMajor()
{
  return major;
}

void Student::setMSSV(string newMSSV)
{
  this->MSSV = newMSSV;
}

void Student::setMajor(string newMajor)
{
  this->major = newMajor;
}
