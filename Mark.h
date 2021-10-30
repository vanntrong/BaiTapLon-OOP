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
						<< "-----Input Mark-----" << std::endl;
	std::cout << "Input GPA: ";
	is >> newMark.GPA;
	std::cout << "Input training point: ";
	is >> newMark.trainingPoint;
	std::cout << "Input extra point: ";
	is >> newMark.extraPoint;
	std::cout << "--------------------" << std::endl;
	return is;
}

//overloading ham xuat
std::ostream &operator<<(std::ostream &os, const Mark &newMark)
{
	os << "GPA: " << newMark.GPA << std::endl;
	os << "Training point: " << newMark.trainingPoint << std::endl;
	os << "Extra point: " << newMark.extraPoint << std::endl;
	return os;
}