
#include <iostream>
#include <string>
#include <math.h>

// using namespace std;

class Date
{
protected:
  int day, month, year;

public:
  Date();
  Date(int day, int month, int year);
  ~Date();
  friend std::istream &operator>>(std::istream &is, Date &newDate);
  friend std::ostream &operator<<(std::ostream &os, const Date &newDate);
};

//ham khoi tao khong doi so
Date::Date()
{
  this->day = this->month = this->year = 0;
}

//Ham khoi tao co doi so
Date::Date(int day, int month, int year)
{
  this->day = day;
  this->month = month;
  this->year = year;
}

//Ham huy
Date::~Date()
{
}

//overloading ham nhap
std::istream &operator>>(std::istream &is, Date &newDate)
{
  std::cout << "Input day: ";
  is >> newDate.day;
  std::cout << "Input month: ";
  is >> newDate.month;
  std::cout << "Input year: ";
  is >> newDate.year;
  return is;
}

//overloading ham xuat
std::ostream &operator<<(std::ostream &os, const Date &newDate)
{
  os << newDate.day << "/" << newDate.month << "/" << newDate.year << std::endl;
  return os;
}