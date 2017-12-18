#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
	char MaSo[50];
	char ten[100];
	int GioiTinh, nam, ChucVu, luong;
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
void NhapNhanVien(NhanVien &x)
{
	cin.ignore();
	cout << "\nNhap ho va ten: "; 
	cin.getline(x.ten, 50);
	cout << "\nNhap ma nhan vien: "; cin >> x.MaSo;
	do {
		cout << "\nNhap nam sinh: "; cin >> x.nam;
		if (x.nam < 1917 || x.nam>2017) {
			cout << "\nNam ban nhap  khong hop le, vui long nhap lai!";
		}
	} while (x.nam < 1917 || x.nam>2017);
	do {
		cout << "\nNhap vao gioi tinh(nam la 1, nu la 0): ";
		cin >> x.GioiTinh;
		if (x.GioiTinh != 0 && x.GioiTinh != 1) {
			cout << "\nGioi tinh nhap khong hop le! nhap lai";
		}
	} while (x.GioiTinh != 0 && x.GioiTinh != 1);
	do {
		cout << "\nNhap chuc vu theo so tuong ung (1: Nhan vien, 2: pho phong, 3: truong phong, 4: pho giam doc, 5: giam doc): ";
		cin >> x.ChucVu;
		if (x.ChucVu < 1 || x.ChucVu>5) {
			cout << "\nNhap sai!, nhap lai nao: ";
		}
	} while (x.ChucVu < 1 || x.ChucVu>5);

}
void XuatNhanVien(NhanVien x)
{
	cout << "\nHo va ten: " << x.ten;
	cout << "\nMa so: " << x.MaSo;
	cout << "\nNam sinh: " << x.nam;
	cout << "\nGioi tinh: ";
	if (x.GioiTinh == 1) {
		cout << " nam";
	}
	else {
		cout << " Nu";
	}
	cout << "\nChuc vu: ";
	if (x.ChucVu == 1) cout << " Nhan vien ";
	if (x.ChucVu == 2) cout << " Pho phong ";
	if (x.ChucVu == 3) cout << " Truong phong ";
	if (x.ChucVu == 4) cout << " Pho giam doc ";
	if (x.ChucVu == 5) cout << " Giam doc ";
	
	//cout << "\nLuong: ";

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
Node *CreateNode(NhanVien x)
{
	Node *p = new Node;
	if (p = NULL) {
		return NULL;
	}
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddList(List &l)
{
	int n;
	NhanVien x;
	cout << "\nNhap vao so nhan vien can nhap: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin nhan vien thu " << i + 1 << ": ";
		NhapNhanVien(x);
		Node *p = CreateNode(x);
		AddHead(l, p);
	}
}

void XuatList(List l)
{
	int i = 1;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		cout << "\nThong tin nhan vien thu " << i << " la: ";
		XuatNhanVien(p->info);
		i++;
	}
}
void TimNhanVienMax(List l)
{
	Node *q = new Node;
	int max = l.pHead->info.nam;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (q->info.GioiTinh == 1) {
			if (p->info.nam < max)
				max = p->info.nam;
			q = p;
		}
	}
	cout << "\nTuoi lon nhat: ";
	XuatNhanVien(q->info);
}
void TinhLuong(List &l)
{
	int a;
	cout << "\nNhap vao muc luong co ban: "; 
	cin >> a;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (p->info.ChucVu == 1)
			p->info.luong = a * 1;
		if (p->info.ChucVu == 2)
			p->info.luong = a * 2;
		if (p->info.ChucVu == 3)
			p->info.luong = a * 3;
		if (p->info.ChucVu == 4)
			p->info.luong = a * 4;
		if (p->info.ChucVu == 5)
			p->info.luong = a * 5;
	}
}
void TimNhanVien(List l)
{
	NhanVien x;
	char b[50];
	//Node *q = new Node;
	cout << "\nNhap vao ma nhan vien can tim: ";
	cin >> b;
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		if (b == p->info.MaSo) {
			cout << "\nNhan vien co trong danh sach! ";
		}
	}
}
int main()
{
	List l;
	NhanVien x;
	CreateList(l);
	int n;
	AddList(l);
	TinhLuong(l);
	XuatList(l);
	TimNhanVien(l);
	XuatList(l);
	TimNhanVienMax(l);
	XuatList(l);
	system("pause");
	return 0;
}