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
	float getGPA();
	float getTrainingPoint();
	float getExtraPoint();
	void Input2();
	void OutPut2();
	void setMark(Mark newMark);
};

Mark::Mark()
{
	this->GPA = this->trainingPoint = this->extraPoint = 0;
}

Mark::Mark(float GPA, float trainingPoint, float extraPoint)
{
	this->GPA = GPA;
	this->trainingPoint = trainingPoint;
	this->extraPoint = extraPoint;
}

Mark::~Mark()
{
}

void Mark::Input2()
{
	std::cout
			<< "\t--------Nhập điểm--------" << std::endl;
	std::cout << "\tNhập điểm trung bình : ";
	std::cin >> this->GPA;
	std::cout << "\tNhập điểm rèn luyện: ";
	std::cin >> this->trainingPoint;
	std::cout << "\tNhập điểm cộng : ";
	std::cin >> this->extraPoint;
	std::cout << "\t--------------------------" << std::endl;
}

void Mark::OutPut2()
{
	std::cout << "||" << this->GPA << "\t\t\t";
	std::cout << "||" << this->trainingPoint << "\t\t\t";
	std::cout << "||" << this->extraPoint << "\t\t\t\n";
}

float Mark::getGPA()
{
	return GPA;
}

float Mark::getTrainingPoint()
{
	return trainingPoint;
}

float Mark::getExtraPoint()
{
	return trainingPoint;
}

void Mark::setMark(Mark newMark)
{
	this->GPA = newMark.GPA;
	this->extraPoint = newMark.extraPoint;
	this->trainingPoint = newMark.trainingPoint;
}