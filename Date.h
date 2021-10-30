
#include <iostream>
#include <string>
#include <math.h>

// using namespace std;

class Date
{
private:
  int day, month, year;

public:
  Date();
  Date(int day, int month, int year);
  ~Date();
  friend std::istream &operator>>(std::istream &is, Date &newDate);
  friend std::ostream &operator<<(std::ostream &os, const Date &newDate);
};

Date::Date()
{
  this->day = this->month = this->year = 0;
}

Date::Date(int day, int month, int year)
{
  this->day = day;
  this->month = month;
  this->year = year;
}

Date::~Date()
{
}

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

std::ostream &operator<<(std::ostream &os, const Date &newDate)
{
  os << "Day: " << newDate.day << std::endl;
  os << "Month: " << newDate.month << std::endl;
  os << "Year: " << newDate.year << std::endl;
  return os;
}