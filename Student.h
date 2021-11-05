#include <iostream>
#include <string>
#include <math.h>
#include "People.h"
#include "Mark.h"

class Student : public People, public Mark
{
private:
  string MSSV;
  Mark newMark;

public:
  friend std::istream &operator>>(std::istream &is, Student &newStudent);
  friend std::ostream &operator<<(std::ostream &os, Student &newStudent);
  string getFullName();
  string getMSSV();
};

std::istream &operator>>(std::istream &is, Student &newStudent)
{
  std::cout << std::endl
            << "\t**********Input**********" << std::endl
            << std::endl;
  std::cout << "\tInput MSSV: ";
  is >> newStudent.MSSV;
  newStudent.Input();
  std::cin >> newStudent.newMark;
  std::cout << std::endl
            << "\t*************************" << std::endl;
  return is;
}

std::ostream &operator<<(std::ostream &os, Student &newStudent)
{
  os << std::endl
     << "\t**********Information**********" << std::endl
     << std::endl;
  os << "\tMSSV: " << newStudent.MSSV << std::endl;
  newStudent.Output();
  std::cout << newStudent.newMark;
  os << "\t*******************************" << std::endl;
  return os;
}

string Student::getFullName()
{
  return fullName;
}

string Student::getMSSV()
{
  return MSSV;
}