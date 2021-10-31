# BaiTapLon-OOP
#include <iostream>
#include <string>

using namespace std;
//khoi tao Node
Node *KhoiTaoNode() {
	sinhvien* sv = new sinhvien;
	Input_ThongTin(sv);
	Node* p = new Node;
	if (p == NULL) {
		cout << " ko thá»ƒ tao thÃªm\n";
		return 0;
	}
	p->data = sv;
	p->link = NULL;
	return p;
}
