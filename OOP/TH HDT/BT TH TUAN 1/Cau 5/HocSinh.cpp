#include "HocSinh.h"



HocSinh::HocSinh()
{
}


HocSinh::~HocSinh()
{
}

void HocSinh::Nhap()
{
	
	cout << "\nNhap ho ten: ";
	cin.getline(ten, 100);
	cout << "\nNhap diem toan: ";
	cin >> toan;
	cout << "\nNhap diem van: ";
	cin >> van;
	cin.ignore();
}

void HocSinh::Xuat()
{
	cout << "\nHo ten: " << ten;
	cout << "\nDiem toan: " << toan;
	cout << "\nDiem van: " << van;
	cout << "\nDiem trung binh: " << (toan + van) / 2 << endl;
}
