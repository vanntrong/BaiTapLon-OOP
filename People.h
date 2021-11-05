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
            << "\t--------Input Info--------" << std::endl;
  std::cout << "\tInput full name: ";
  fflush(stdin);
  getline(cin, this->fullName);
  cout << "\tInput date of birth: " << std::endl;
  std::cin >> this->dateOfBirth;
  std::cout << "\tInput address: ";
  fflush(stdin);
  getline(cin, this->address);
  std::cout << "\t--------------------------" << std::endl;
}

void People::Output()
{
  std::cout << "\tFull name: " << this->fullName << std::endl;
  std::cout << "\tDate of birth: ";
  std::cout << this->dateOfBirth;
  std::cout << "\tAddress: " << this->address << std::endl;
}