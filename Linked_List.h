
#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

struct Node
{
	Student data;
	Node *next;
};

struct listStudent
{
	Node *head;
	Node *tail;
	long size;

	listStudent();

	void initList();
	bool isEmpty();
	void showList();
	void addFirst();
	void addLast();
	void addLast(Node *node);
	void insertAfter(Node *node);
	Node *previous(Node *node);
	void remove(Node *node);
	void removeHead();
	void removeLast();
	Node *findbyName();
	Node *findbyMSSV();
	void removeByMSSV();
	void removeByName();
	void editMSSV(Node *node);
	void editName(Node *node);
	void editDateOfBirth(Node *node);
	void editAddress(Node *node);
	void editMark(Node *node);
	void sortByName();
	void sortByMSSV();
	void sortByMark();
	void studyWarning();
	void writeFile();
};

using namespace std;
//khoi tao Node
Node *createNode()
{
	Student sinhVien;
	cin >> sinhVien;
	Node *p = new Node;
	if (p == NULL)
	{
		cout << "Không thể thêm vào";
		return NULL; //thay return 0 bang return NULL vi kieu du lieu tra ve la node
	}
	p->data = sinhVien;
	p->next = NULL;
	return p;
}

// show node
void showNode(Node *node)
{
	cout << "\t" << node->data;
}

//-----list----------
//khoi tao danh sach rong
void listStudent::initList()
{
	head = tail = NULL;
	size = 0;
}

listStudent::listStudent()
{
	head = tail = NULL;
	size = 0;
}

bool listStudent::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

void listStudent::showList()
{
	Node *node = head;
	int i = 0;
	cout << "\t----------List----------" << endl;
	while (node != NULL)
	{
		cout << "\tStudent " << i + 1 << ": " << endl;
		showNode(node);
		node = node->next;
		i++;
	}
	cout << "\t------------------------" << endl;
}

void listStudent::addFirst()
{
	Node *p = createNode();
	p->next = head;
	head = p;
	if (size == 0)
		tail = p;
	size++;
}

void listStudent::addLast()
{
	Node *node = createNode();
	if (isEmpty())
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
		// delete node;
	}
	size++;
}

void listStudent::addLast(Node *node)
{
	if (isEmpty())
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
	size++;
}

void listStudent::insertAfter(Node *node)
{
	if (node == tail)
	{
		addLast();
	}
	else
	{
		Node *newNode = createNode();
		newNode->next = node->next;
		node->next = newNode;
	}
	size++;
}

Node *listStudent::previous(Node *node)
{
	Node *previousNode = head;
	while (previousNode->next != node)
		previousNode = previousNode->next;
	return previousNode;
}

void listStudent::remove(Node *node)
{
	if (node == head)
	{
		removeHead();
		return;
	}
	if (node == tail)
	{
		removeLast();
		return;
	}
	Node *pre = previous(node);
	pre->next = node->next;
	delete node;
	size--;
}

void listStudent::removeHead()
{
	if (isEmpty())
	{
		cout << "Danh sách rỗng!!!" << endl;
		return;
	}
	else
	{
		Node *node = head;
		head = head->next;
		delete node;
		size--;
	}
}

void listStudent::removeLast()
{
	if (isEmpty())
	{
		cout << "Danh sách rỗng!!!" << endl;
		return;
	}
	for (Node *p = head; p != NULL; p = p->next)
	{
		if (p->next == tail)
		{
			delete tail;
			p->next = NULL;
			tail = p;
			return;
		}
	}
}

void listStudent::removeByMSSV()
{
	string mssv;
	cout << "\tNhập MSSV bạn cần xóa : ";
	fflush(stdin);
	getline(cin, mssv);
	Node *node = head;
	while (node != NULL)
	{
		//	if (node->data.getFullName() != mssv)
		//	{
		//		cout << "Không có sinh viên này!!!\n";
		//		cout << "Vui lòng nhập lại MSSV: ";
		//		fflush(stdin);
		//		getline(cin, mssv);
		//		Node *node = head;
		//	}
		//	else
		if (node->data.getMSSV() == mssv)
		{
			remove(node);
			cout << "\tHoàn thành";
			return;
		}
		else
		{
			node = node->next;
		}
	}
}

void listStudent::removeByName()
{
	string name;
	cout << "\tNhập tên sinh viên bạn cần xóa : ";
	fflush(stdin);
	getline(cin, name);
	Node *node = head;
	while (node != NULL)
	{
		//	if (node->data.getFullName() != name)
		//	{
		//		cout << "Không có sinh viên này!!!\n";
		//		cout << "Vui lòng nhập lại tên sinh viên: ";
		//		fflush(stdin);
		//		getline(cin, name);
		//		Node *node = head;
		//	}
		//	else
		if (node->data.getFullName() == name)
		{
			remove(node);
			cout << "\tHoàn thành!";
			return;
		}
		else
		{
			node = node->next;
		}
	}
}

Node *listStudent::findbyName() // sửa kiểu trả về từ void thành Node
{
	string name;
	cout << "\tNhập tên sinh viên bạn cần tìm : ";
	fflush(stdin);
	getline(cin, name);
	Node *p = head;
	while (p != NULL)
	{
		// dung ham getFullName de tra ve fullname
		if (p->data.getFullName() == name)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL; // thêm return NULL để khi không tìm thấy sẽ trả về NULL
}

Node *listStudent::findbyMSSV() // sửa kiểu trả về từ void thành Node
{
	string MSSV;
	cout << "\tNhập mã số của sinh viên bạn cần tìm : ";
	fflush(stdin);
	getline(cin, MSSV);
	Node *p = head;
	while (p != NULL)
	{
		// dung ham get mssv de tra ve mssv
		if (p->data.getMSSV() == MSSV)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL; // thêm return NULL để khi không tìm thấy sẽ trả về NULL
}

void listStudent::editMSSV(Node *node)
{
	string MSSV;
	cout << "\tNhập MSSV mới : ";
	fflush(stdin);
	getline(cin, MSSV);
	node->data.setMSSV(MSSV);
	cout << "\tHoàn thành!";
}

void listStudent::editName(Node *node)
{
	string name;
	cout << "\tNhập tên mới :  ";
	fflush(stdin);
	getline(cin, name);
	node->data.setName(name);
	cout << "\tHoàn thành!";
}

void listStudent::editDateOfBirth(Node *node)
{
	Date newDate;
	cout << "\tNhập ngày sinh mới : ";
	cin >> newDate;
	node->data.setDateOfBirth(newDate);
	cout << "\tHoàn thành!";
}

void listStudent::editAddress(Node *node)
{
	string newAddress;
	cout << "\tNhập địa chỉ mới : ";
	cin >> newAddress;
	node->data.setAddress(newAddress);
	cout << "\tHoàn thành!";
}

void listStudent::editMark(Node *node)
{
	Mark newMark;
	cout << "\tNhập điểm số mới : ";
	// cin >> newMark;
	newMark.Input2();
	node->data.setMark(newMark);
	cout << "\tHoàn thành!";
}

void swapNode(Node *node1, Node *node2)
{
	Student temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

void listStudent::sortByName()
{
	for (Node *node1 = head; node1 != NULL; node1 = node1->next)
	{
		for (Node *node2 = node1->next; node2 != NULL; node2 = node2->next)
		{
			if (node1->data.getFullName() > node2->data.getFullName())
			{
				swapNode(node1, node2);
			}
		}
	}
	cout << "\tHoàn thành!";
}

void listStudent::sortByMSSV()
{
	for (Node *node1 = head; node1 != NULL; node1 = node1->next)
	{
		for (Node *node2 = node1->next; node2 != NULL; node2 = node2->next)
		{
			if (node1->data.getMSSV() > node2->data.getMSSV())
			{
				swapNode(node1, node2);
			}
		}
	}
	cout << "\tHoàn thành!";
}

void listStudent::sortByMark()
{
	for (Node *node1 = head; node1 != NULL; node1 = node1->next)
	{
		for (Node *node2 = node1->next; node2 != NULL; node2 = node2->next)
		{
			if (node1->data.getGPA() > node2->data.getGPA())
			{
				swapNode(node1, node2);
			}
		}
	}
	cout << "\tHoàn thành!";
}

void listStudent::studyWarning()
{
	int sizeWarning = 0;
	Node *node = head;
	while (node != NULL)
	{
		if (node->data.getGPA() < 4)
		{
			showNode(node);
			sizeWarning++;
		}
		node = node->next;
	}
	if (sizeWarning == 0)
	{
		cout << "\t\t\t\t\tKhông có sinh viên bị cảnh cáo học tập";
	}
}

void listStudent::writeFile()
{
	fstream fileSV;
	fileSV.open("Student.txt", ios::out | ios::app);
	fileSV << "STT\t\t\tMã sinh viên\t\t\tHọ và tên\t\t\tNgày sinh\t\t\tĐịa chỉ\t\t\tĐiểm trung bình\t\t\tĐiểm rèn luyện\t\t\tĐiểm cộng" << endl;
	Node *node = head;
	int i = 0;
	while (node != NULL)
	{
		fileSV << " " << i + 1 << "\t\t\t" << node->data.getMSSV() << "\t\t\t" << node->data.getFullName() << "\t\t" << node->data.getDay() << "/" << node->data.getMonth() << "/" << node->data.getYear() << "\t\t" << node->data.getAddress() << "\t\t\t\t" << node->data.getGPA() << "\t\t\t\t" << node->data.getTrainingPoint() << "\t\t\t\t" << node->data.getExtraPoint() << endl;

		node = node->next;
	}
	fileSV.close();
	cout << "\tHoàn thành";
}