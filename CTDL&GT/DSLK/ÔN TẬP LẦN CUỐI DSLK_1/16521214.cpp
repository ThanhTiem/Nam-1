//Ho va ten: Le Thanh Tiem
//MSSV: 16521214
//May so: 35
//De 1

#include <iostream>
#include <string>
#include<fstream>
using namespace std;
//Khai bao co ban: 
struct NhanVien
{
	char MaSo[50];
	char HoTen[100];
	int GioiTinh, NamSinh, ChucVu, Luong;
};
struct Node
{
	NhanVien info;
	struct Node *pNext;
};
struct List
{
	Node *pHead;
	Node *pTail;
};
void CreateList(List &l)
{
	l.pHead = l.pTail = NULL;
}
Node *CreateNode(NhanVien x)
{
	Node *p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddHead(List &l, Node *p)
{
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(List &l, Node *p)
{
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
//Cau 1: 
void NhapNhanVien(NhanVien &x)
{
	cin.ignore();
	cout << "\nNhap vao ma so nhan vien: ";
	cin.getline(x.MaSo, 50);
	
	cout << "\nNhap vao ho va ten: ";
	cin.getline(x.HoTen, 100);
	do {
		cout << "\nNhap vao Gioi tinh (1: nam, 0: nu): ";
		cin >> x.GioiTinh;
		if (x.GioiTinh != 0 && x.GioiTinh != 1) {
			cout << "\nNhap gioi tinh sai, vui long nhap lai! ";
		}
	} while (x.GioiTinh != 0 && x.GioiTinh != 1);
	cout << "\nNhap vao nam sinh: ";
	cin >> x.NamSinh;
	do {
		cout << "\nNhap vao chuc vu (1: Nhan vien, 2: Pho phong, 3: Truong phong, 4: Pho giam doc, 5: Giam doc): ";
		cin >> x.ChucVu;
		if (x.ChucVu < 1 || x.ChucVu>5)
			cout << "\nBan nhap chuc vu khong phu hop! vui long nhap lai.";
	} while (x.ChucVu < 1 || x.ChucVu>5);
}
void XuatNhanVien(NhanVien x)
{
	cout << "\nMa so: " << x.MaSo;
	cout << "\nHo va ten: " << x.HoTen;
	cout << "\nGioi tinh: ";
	if (x.GioiTinh == 0)
		cout << " Nu";
	if (x.GioiTinh == 1)
		cout << " Nam";
	cout << "\nNam sinh: " << x.NamSinh;
	cout << "\nChuc vu: ";
	if (x.ChucVu == 1)
		cout << " Nhan vien.";
	if (x.ChucVu == 2)
		cout << " Pho phong.";
	if (x.ChucVu == 3)
		cout << " Truong phong.";
	if (x.ChucVu == 4)
		cout << " Pho Giam doc.";
	if (x.ChucVu == 5)
		cout << " Giam doc.";
}
void AddList(List &l)
{
	int n;
	cout << "\nNhap vao so luong nhan vien: ";
	cin >> n;
	NhanVien x;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap vao nhan vien thu " << i + 1 << " : ";
		NhapNhanVien(x);
		Node *p = CreateNode(x);
		AddHead(l, p);
	}
}
void XuatList(List l)
{
	int i = 1;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		cout << "\nThong tin Nhan vien thu " << i << " la: ";
		XuatNhanVien(p->info);
		i++;
	}
}
void TinhLuong(List l)
{
	//fstream f;
	//f.open("TEST.TXT", ios::out);
	int a, i=1;
	//NhanVien x;
	cout << "\nNhap vao muc luong co ban: ";
	cin >> a;
	cout << "\nMuc luong cua moi nhan vien la: ";
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		p->info.Luong = a*p->info.ChucVu;
		
		XuatNhanVien(p->info);
		cout << "\nLuong: " << p->info.Luong;
		i++;
	}
	//f.close();
}
void TimNhanVien(List l)
{
	char a[50];
	cout << "\nNhap vao MSNV can tim: ";
	cin >> a;
	Node*q = l.pHead;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (a == p->info.MaSo) {
			cout << "\nNhan vien co trong danh sach!";
			q = p;
		}
	}
	XuatNhanVien(q->info);
}
void NhanVienNu_Max(List l)
{
	int max = l.pHead->info.NamSinh;
	Node *a = l.pHead;
	Node *b = l.pHead;
	int min = l.pHead->info.NamSinh;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (p->info.GioiTinh==0 && p->info.NamSinh < max) {
			max = p->info.NamSinh;
			a = p;
		}
		if (p->info.GioiTinh == 0 && p->info.NamSinh > min) {
			min = p->info.NamSinh;
			b = p;
		}
	}
	cout << "\nThong tin nhan vien NU co tuoi LON NHAT la: ";
	XuatNhanVien(a->info);
	cout << "\nThong tin nhan vien NU co tuoi NHO NHAT la: ";
	XuatNhanVien(b->info);
}
void NhanVienNam_Max(List l)
{
	int max = l.pHead->info.NamSinh;
	Node *a = l.pHead;
	Node *b = l.pHead;
	int min = l.pHead->info.NamSinh;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (p->info.GioiTinh==1 && p->info.NamSinh < max) {
			max = p->info.NamSinh;
			a = p;
		}
		if (p->info.GioiTinh == 1 && p->info.NamSinh > min) {
			min = p->info.NamSinh;
			b = p;
		}
	}
	cout << "\nThong tin nhan vien NAM co tuoi LON NHAT la: ";
	XuatNhanVien(a->info);
	cout << "\nThong tin nhan vien NAM co tuoi NHO NHAT la: ";
	XuatNhanVien(b->info);
}

int main()
{
	List l;
	CreateList(l);
	AddList(l);
	
	XuatList(l);
	
	TinhLuong(l);
	TimNhanVien(l);
	NhanVienNu_Max(l);
	NhanVienNam_Max(l);
	
	system("pause");
	return 0;
}