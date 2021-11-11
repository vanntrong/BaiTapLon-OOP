#include "Date.h"

using namespace std;

class People : public Date
{
protected:
  string fullName;
  Date dateOfBirth;
  string address;

public:
  People();
  void Input();
  void Output();
  void setName(string newName);
  void setDateOfBirth(Date newDate);
  void setAddress(string newAddress);
};

People::People() : Date()
{
  fullName = "";
  // Date::Date();
  address = "";
}

//overloading ham nhap
void People::Input()
{
  std::cout << std::endl
            << "\t--------Nhập thông tin--------" << std::endl;
  std::cout << "\tNhập tên đầy đủ : ";
  fflush(stdin);
  getline(cin, this->fullName);
  cout << "\tNhập ngày sinh : " << std::endl;
  std::cin >> this->dateOfBirth;
  std::cout << "\tNhập địa chỉ : ";
  fflush(stdin);
  getline(cin, this->address);
  std::cout << "\t--------------------------" << std::endl;
}

//overloading ham xuat
void People::Output()
{
  std::cout << "\tHọ và tên : " << this->fullName << std::endl;
  std::cout << "\tNgày sinh : ";
  std::cout << this->dateOfBirth;
  std::cout << "\tĐịa chỉ : " << this->address << std::endl;
}

//ham sua ten
void People::setName(string newName)
{
  this->fullName = newName;
}

//ham sua ngay sinh
void People::setDateOfBirth(Date newDate)
{
  this->dateOfBirth = newDate;
}

//ham sua dia chi
void People::setAddress(string newAddress)
{
  this->address = newAddress;
}