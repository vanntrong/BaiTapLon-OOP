#include <iostream>
#include <string>
#include <math.h>
#include "People.h"
#include "Mark.h"

class Student : public People, public Mark
{
private:
  string MSSV;
  // Mark newMark;

public:
  Student();
  friend std::istream &operator>>(std::istream &is, Student &newStudent);
  friend std::ostream &operator<<(std::ostream &os, Student &newStudent);
  string getMSSV();
  void setMSSV(string newMSSV);
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
  newStudent.Input2();
  std::cout << std::endl
            << "\t*************************" << std::endl;
  return is;
}

std::ostream &operator<<(std::ostream &os, Student &newStudent)
{
  // os << std::endl
  //    << "\t**********Information**********" << std::endl
  //    << std::endl;
  // os << "\tMSSV: " << newStudent.MSSV << std::endl;
  // newStudent.Output();
  // newStudent.OutPut2();
  // os << "\t*******************************" << std::endl;
  os << "||" << newStudent.MSSV << "\t\t";
  newStudent.Output();
  newStudent.OutPut2();
  return os;
}

string Student::getMSSV()
{
  return MSSV;
}

void Student::setMSSV(string newMSSV)
{
  this->MSSV = newMSSV;
}
