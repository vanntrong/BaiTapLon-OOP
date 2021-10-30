#include <iostream>
#include <string>
#include <math.h>
#include "People.h"
#include "Mark.h"

class Student : public People, public Mark
{
private:
  string MSSV;
  People newPeople;
  Mark newMark;

public:
  friend std::istream &operator>>(std::istream &is, Student &newStudent);
  friend std::ostream &operator<<(std::ostream &os, Student &newStudent);
};

std::istream &operator>>(std::istream &is, Student &newStudent)
{
  std::cout << std::endl
            << "**********Input**********" << std::endl
            << std::endl;
  std::cout << "Input MSSV: ";
  is >> newStudent.MSSV;
  std::cin >> newStudent.newPeople;
  std::cin >> newStudent.newMark;
  std::cout << std::endl
            << "*************************" << std::endl;
  return is;
}

std::ostream &operator<<(std::ostream &os, Student &newStudent)
{
  os << std::endl
     << "**********Information**********" << std::endl
     << std::endl;
  os << "MSSV: " << newStudent.MSSV << std::endl;
  std::cout << newStudent.newPeople;
  std::cout << newStudent.newMark;
  os << "*******************************" << std::endl;
  return os;
}