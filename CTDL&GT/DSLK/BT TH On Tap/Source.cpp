#include <iostream>
#include <string>
using namespace std;

struct CongNhan
{
	char HoTen[50];
	int GioiTinh, NamSinh, SanPham;
	int Luong;
};
struct Node
{
	CongNhan info;
	struct Node *pNext;
};
struct List
{
	Node *pHead;
	Node *pTail;
};
void CreateList (List &l)
{
	l.pHead = l.pTail = NULL;
}
Node* CreateNode(CongNhan x)
{
	Node *p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->info = x;
	p->pNext = NULL;
	return p;
}
void NhapCongNhan(CongNhan &x)
{
	cin.ignore();
	cout << "\nNhap vao Ho va ten: ";
	cin.getline(x.HoTen, 50);
	do {
		cout << "\nNhap vao gioi tinh (Nam nhap 1, Nu nhap 0): ";
		cin >> x.GioiTinh;
		if (x.GioiTinh != 1 && x.GioiTinh != 0) {
			cout << "\nGioi tinh nhap sai, nhap lai! ";
		}
	} while (x.GioiTinh != 1 && x.GioiTinh != 0);
	cout << "\nNhap vao nam sinh: ";
	cin >> x.NamSinh;
	cout << "\nNhap vao so san pham may: ";
	cin >> x.SanPham;
}
void XuatThongTin(CongNhan x)
{
	cout << "\n------------------";
	cout << "\nHo ten: " << x.HoTen;
	cout << "\nGioi tinh: ";
	if (x.GioiTinh == 1)
		cout << "Nam.";
	else
		cout << "Nu.";
	cout << "\nNam sinh: " << x.NamSinh;
	cout << "\nSo san pham may: " << x.SanPham;
	
}
void AddHead(List &l, Node* p)
{
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddList(List &l)
{
	int n;
	CongNhan x;
	cout << "\nNhap vao so cong nhan: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "\nNhap vao thong tin cong nhan thu " << i + 1 << " : ";
		NhapCongNhan(x);
		Node *p = CreateNode(x);
		AddHead(l, p);
	}
}
void XuatList(List l)
{
	int i = 1;
	for (Node* p = l.pHead; p != NULL; p = p->pNext) {
		cout << "\nThong tin cong nhan thu " << i << " :";
		XuatThongTin(p->info);
		i++;
	}
}
void TimCongNhanMax(List l)
{
	Node *q = l.pHead;
	int max = l.pHead->info.NamSinh;
	for (Node*p = l.pHead; p != NULL; p = p->pNext) {
		if (p->info.NamSinh < max) {
			max = p->info.NamSinh;
			q = p;
		}
	}
	//cout << "\n================" << endl;
	cout << "\nCong nhan co tuoi lon nhat la: ";
	XuatThongTin(q->info);
}
//void search(List l) {
//	int max = l.pHead->info.NamSinh;
//	for (Node* p = l.pHead; p != NULL; p = p->pNext)
//		if (p->info.NamSinh < max)
//			max = p->info.NamSinh;
//	for (Node* p = l.pHead; p != NULL; p = p->pNext)
//		if (p->info.NamSinh == max)
//		{
//			if (p == NULL)
//				cout << "danh sach rong";
//			if (p != NULL)
//			{
//				cout << "\nCong nhan lon tuoi nhat: ";
//				cout << "\nHo va ten: " << p->info.HoTen;
//				cout << "\nGioi tinh: ";
//				if (p->info.GioiTinh == 1)
//					cout << "Nam.";
//				else
//					cout << "Nu.";
//				cout << "\nNam sinh: " << p->info.NamSinh;
//				//XuatThongTin(p->info);
//			}
//		}
//}
void TinhLuong(List &l)
{
	
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (p->info.GioiTinh == 1)
			p->info.Luong = p->info.SanPham * 50;
		else
			p->info.Luong = p->info.SanPham * 50 * 1.5;
		XuatThongTin(p->info);
		cout << "\nLuong: " << p->info.Luong;
		cout << "\n----------------------------------";
	}
}
void SapXep(List l)
{
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		for (Node*q = p->pNext; q != NULL; q = q->pNext) {
			if (p->info.Luong > q->info.Luong) {
				CongNhan temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
	cout << "\nCong nhan sau khi sap xep tang dan theo luong la: ";
}
int main()
{
	List l;
	CongNhan x;
	int n;
	CreateList(l);
	AddList(l);
	XuatList(l);
	TimCongNhanMax(l);
	//search(l);
	cout << "\nLuong cua cong nhan: ";
	TinhLuong(l);
	SapXep(l);
	
	XuatList(l);
	system("pause");
	return 0;
}