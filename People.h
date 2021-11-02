#include "Date.h"

using namespace std;

class People : public Date
{
protected:
  string fullName;
  Date dateOfBirth;
  string address;

public:
  void Input();
  void Output();
};

//overloading ham nhap
void People::Input()
{
  std::cout << std::endl
            << "-----Input Info-----" << std::endl;
  std::cout << "Input full name: ";
  fflush(stdin);
  getline(cin, this->fullName);
  cout << "Input date of birth: " << std::endl;
  std::cin >> this->dateOfBirth;
  std::cout << "Input address: ";
  fflush(stdin);
  getline(cin, this->address);
  std::cout << "--------------------" << std::endl;
}

void People::Output()
{
  std::cout << "Full name: " << this->fullName << std::endl;
  std::cout << "Date of birth: " << std::endl;
  std::cout << this->dateOfBirth;
  std::cout << "Address: " << this->address << std::endl;
}