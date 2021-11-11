#include <iostream>
#include <string>
#include <math.h>

class Mark
{
protected:
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
	std::cout
			<< "\t--------Nhập điểm--------" << std::endl;
	std::cout << "\tNhập điểm trung bình : ";
	is >> newMark.GPA;
	std::cout << "\tNhập điểm rèn luyện: ";
	is >> newMark.trainingPoint;
	std::cout << "\tNhập điểm cộng : ";
	is >> newMark.extraPoint;
	std::cout << "\t--------------------------" << std::endl;
	return is;
}

//overloading ham xuat
std::ostream &operator<<(std::ostream &os, const Mark &newMark)
{
	os << "\tĐiểm trung bình : " << newMark.GPA << std::endl;
	os << "\tĐiểm rèn luyện :  " << newMark.trainingPoint << std::endl;
	os << "\tĐiểm cộng : " << newMark.extraPoint << std::endl;
	return os;
}