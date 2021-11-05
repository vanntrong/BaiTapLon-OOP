#include <iostream>
#include <string>
#include <math.h>

class Mark
{
private:
	float GPA;					 //diem trung binh
	float trainingPoint; //diem ren luyen
	float extraPoint;		 //diem cong
public:
	Mark();
	Mark(float GPA, float trainingPoint, float extraPoint);
	~Mark();
	friend std::istream &operator>>(std::istream &is, Mark &newMark);
	friend std::ostream &operator<<(std::ostream &os, const Mark &newMark);
};

// Khai bao khong doi so
Mark::Mark()
{
	this->GPA = this->trainingPoint = this->extraPoint = 0;
}

// Khai bao co doi so
Mark::Mark(float GPA, float trainingPoint, float extraPoint)
{
	this->GPA = GPA;
	this->trainingPoint = trainingPoint;
	this->extraPoint = extraPoint;
}

//Ham huy
Mark::~Mark()
{
}

//oveloading ham nhap
std::istream &operator>>(std::istream &is, Mark &newMark)
{
	std::cout << std::endl
						<< "\t--------Input Mark--------" << std::endl;
	std::cout << "\tInput GPA: ";
	is >> newMark.GPA;
	std::cout << "\tInput training point: ";
	is >> newMark.trainingPoint;
	std::cout << "\tInput extra point: ";
	is >> newMark.extraPoint;
	std::cout << "\t--------------------------" << std::endl;
	return is;
}

//overloading ham xuat
std::ostream &operator<<(std::ostream &os, const Mark &newMark)
{
	os << "\tGPA: " << newMark.GPA << std::endl;
	os << "\tTraining point: " << newMark.trainingPoint << std::endl;
	os << "\tExtra point: " << newMark.extraPoint << std::endl;
	return os;
}