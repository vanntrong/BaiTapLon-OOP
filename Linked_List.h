
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
	void findbyName();
	void findbyMSSV();
	void removeByMSSV();
	void removeByName();
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
		cout << " Khong the them vao";
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
		cout << "Error!!!" << endl;
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
		cout << "Error!!!" << endl;
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

// xoa sinh vien o cuoi danh sach
void listStudent::removeByMSSV()
{
	string mssv;
	cout << "\tEnter MSSV you need to delete: ";
	fflush(stdin);
	getline(cin, mssv);
	Node *node = head;
	while (node != NULL)
	{
		if (node->data.getMSSV() == mssv)
		{
			remove(node);
			return;
		}
		else
		{
			node = node->next;
		}
	}
}

// tim kiem sinh vien theo ten
void listStudent::findbyName()
{
	string name;
	cout << "Enter Name you need to find: ";
	fflush(stdin);
	getline(cin, name);
	Node *p = head;
	while (p != NULL)
	{
		// dung ham getFullName de tra ve fullname
		if (p->data.getFullName() == name)
		{
			showNode(p);
			return;
		}
		else
		{
			p = p->next;
		}
	}
}

// tim kiem sinh vien theo MSSV
void listStudent::findbyMSSV()
{
	string MSSV;
	cout << "Enter MSSV you need to find: ";
	fflush(stdin);
	getline(cin, MSSV);
	Node *p = head;
	while (p != NULL)
	{
		// dung ham get mssv de tra ve mssv
		if (p->data.getMSSV() == MSSV)
		{
			showNode(p);
			return;
		}
		else
		{
			p = p->next;
		}
	}
}

//duyet danh sach va in
// void listStudent::PrintList()
// {
// 	// if (head ! = NULL)
// 	// {
// 	// 	Node *node = head;
// 	// 	while (node = NULL)
// 	// 	{
// 	// 		cout << node->data << ' ';
// 	// 		node = node->next;
// 	// 	}
// 	// }

// 	if (isEmpty())
// 	{
// 		cout << "Error!!!";
// 		return;
// 	}
// 	else
// 	{
// 		Node *node = head;
// 		while (node != NULL)
// 		{
// 			cout << node->data;
// 			node = node->next;
// 		}
// 	}
// }
