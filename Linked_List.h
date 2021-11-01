#BaiTapLon - OOP
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

	void initList();
	bool isEmpty();
	void showList();
	void addFirst();
	void addLast();
	Node *previous(Node *p);
	void removeHead();
	// void PrintList();
};

using namespace std;
//khoi tao Node
Node *KhoiTaoNode()
{
	Student *sinhVien = new Student;
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
	cout << node->data;
}

//-----list----------
//khoi tao danh sach rong
void listStudent::initList()
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
	cout << "**********List**********" << endl;
	while (node != NULL)
	{
		cout << "Student " << i + 1 << ": " << endl;
		showNode(node);
		node = node->next;
		i++;
	}
	cout << "************************" << endl;
}

//them mot sinh vien vao dau danh sach
void listStudent::addFirst()
{
	Node *p = CreateNode();
	p->next = head;
	head = p;
	if (size == 0)
		tail = p;
	size++;
}
//them mot sinh vien vao cuoi danh sach
void listStudent::addLast()
{
	Node *node = KhoiTaoNode();
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

//tim mot node truoc node chi dinh
Node *listStudent::previous(Node *p)
{
	Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}
// xoa mot sv dau danh sach
void listStudent::removeHead(int &x)
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
