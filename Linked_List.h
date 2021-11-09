
#include <iostream>
#include <string>
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
	// void PrintList();
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

//kiem tra danh sach co rong khong
bool listStudent::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

//xuat danh sach
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

//them mot sinh vien vao dau danh sach
void listStudent::addFirst()
{
	Node *p = createNode();
	p->next = head;
	head = p;
	if (size == 0)
		tail = p;
	size++;
}
//them mot sinh vien vao cuoi danh sach
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

// them mot node moi vao sau mot node
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

//tim mot node truoc node chi dinh
Node *listStudent::previous(Node *node)
{
	Node *previousNode = head;
	while (previousNode->next != node)
		previousNode = previousNode->next;
	return previousNode;
}

// xoa mot sinh vien bat ki
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

// xoa mot sv dau danh sach
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

// xoa sinh vien cuoi danh sach
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

// xoa sinh vien theo mssv
void listStudent::removeByMSSV()
{
	string mssv;
	cout << "\tNhập MSSV bạn cần xóa : ";
	fflush(stdin);
	getline(cin, mssv);
	Node *node = head;
	while (node != NULL)
	{
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

//xoa sinh vien theo ten
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

// tim kiem sinh vien theo ten
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

// tim kiem sinh vien theo MSSV
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

//khoi tao ham sua mssv
void listStudent::editMSSV(Node *node)
{
	string MSSV;
	cout << "\tNhập MSSV mới : ";
	fflush(stdin);
	getline(cin, MSSV);
	node->data.setMSSV(MSSV);
	cout << "\tHoàn thành!";
}

//khoi tao ham sua ten
void listStudent::editName(Node *node)
{
	string name;
	cout << "\tNhập tên mới :  ";
	fflush(stdin);
	getline(cin, name);
	node->data.setName(name);
	cout << "\tHoàn thành!";
}

//khoi tao ham sua ngay sinh
void listStudent::editDateOfBirth(Node *node)
{
	Date newDate;
	cout << "\tNhập ngày sinh mới : ";
	cin >> newDate;
	node->data.setDateOfBirth(newDate);
	cout << "\tHoàn thành!";
}

//khoi tao ham sua địa chỉ
void listStudent::editAddress(Node *node)
{
	string newAddress;
	cout << "\tNhập địa chỉ mới : ";
	cin >> newAddress;
	node->data.setAddress(newAddress);
	cout << "\tHoàn thành!";
}

//khoi tao ham sua diem
void listStudent::editMark(Node *node)
{
	Mark newMark;
	cout << "\tNhập điểm số mới : ";
	cin >> newMark;
	node->data.setMark(newMark);
	cout << "\tHoàn thành!";
}