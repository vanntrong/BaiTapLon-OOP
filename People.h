#include <iostream>
#include <string>
#include <math.h>
#include "Date.h"

using namespace std;

class People : public Date
{
private:
  string fullName;
  Date dateOfBirth;
  string address;
};