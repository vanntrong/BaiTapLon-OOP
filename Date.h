
#include <iostream>
#include <string>
#include <math.h>

// using namespace std;

class Date
{
public:
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
  std::cout << "\n\t\tNhập ngày : ";
  is >> newDate.day;
  std::cout << "\t\tNhập tháng : ";
  is >> newDate.month;
  std::cout << "\t\tNhập năm : ";
  is >> newDate.year;
  std::cout << std::endl;
  return is;
}

//overloading ham xuat
std::ostream &operator<<(std::ostream &os, const Date &newDate)
{
  os << newDate.day << "/" << newDate.month << "/" << newDate.year;
  return os;
}