#include "Date.h"

using namespace std;

class People : public Date
{
private:
  string fullName;
  Date dateOfBirth;
  string address;

public:
  friend std::istream &operator>>(std::istream &is, People &newPeople);
  friend std::ostream &operator<<(std::ostream &os, const People &newPeople);
};

//overloading ham nhap
std::istream &operator>>(std::istream &is, People &newPeople)
{
  std::cout << std::endl
            << "-----Input Info-----" << std::endl;
  std::cout << "Input full name: ";
  fflush(stdin);
  getline(is, newPeople.fullName);
  cout << "Input date of birth: " << std::endl;
  std::cin >> newPeople.dateOfBirth;
  std::cout << "Input address: ";
  fflush(stdin);
  getline(is, newPeople.address);
  std::cout << "--------------------" << std::endl;
  return is;
}

std::ostream &operator<<(std::ostream &os, const People &newPeople)
{
  os << std::endl
     << "**********Information**********" << std::endl
     << std::endl;
  os << "Full name: " << newPeople.fullName << std::endl;
  os << "Date of birth: " << std::endl;
  std::cout << newPeople.dateOfBirth;
  os << "Address: " << newPeople.dateOfBirth << std::endl;
  os << "*******************************" << std::endl;
  return os;
}