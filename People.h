#include "Date.h"

using namespace std;

class People : public Date
{
private:
  string fullName;
  Date dateOfBirth;
  string address;

public:
  People();
  void Input();
  void Output();
  string getFullName();
  string getAddress();
  int getDay();
  int getMonth();
  int getYear();
  void setName(string newName);
  void setDateOfBirth(Date newDate);
  void setAddress(string newAddress);
};

People::People() : Date()
{
  fullName = "";
  address = "";
}

void People::Input()
{
  std::cout << "\tNhập tên đầy đủ : ";
  fflush(stdin);
  getline(cin, this->fullName);
  cout << "\tNhập ngày sinh : " << std::endl;
  std::cin >> this->dateOfBirth;
  std::cout << "\tNhập địa chỉ : ";
  fflush(stdin);
  getline(cin, this->address);
}

void People::Output()
{
  std::cout << "||" << this->fullName << "\t\t\t";
  std::cout << "||";
  std::cout << this->dateOfBirth << "\t\t\t";
  std::cout << "||";
  std::cout << this->address << "\t\t";
}

string People::getFullName()
{
  return fullName;
}

string People::getAddress()
{
  return address;
}

int People::getDay()
{
  return dateOfBirth.day;
}

int People::getMonth()
{
  return dateOfBirth.month;
}

int People::getYear()
{
  return dateOfBirth.year;
}

void People::setName(string newName)
{
  this->fullName = newName;
}

void People::setDateOfBirth(Date newDate)
{
  this->dateOfBirth = newDate;
}

void People::setAddress(string newAddress)
{
  this->address = newAddress;
}