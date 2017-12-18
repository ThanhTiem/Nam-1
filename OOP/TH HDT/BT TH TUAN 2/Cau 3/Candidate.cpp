#include "Candidate.h"

Candidate::Candidate()
{
}


Candidate::~Candidate()
{
}

void Candidate::Nhap()
{

	cout << "\nNhap ma so: ";
	cin >> maso;
	cout << "\nNhap ten: ";
	cin.getline(ten, 100);
	cin.ignore();
	do {
		cout << "\nNhap vao ngay, thang , nam sinh: ";
		cin >> ngay >> thang >> nam;
		if (ngay < 1 || ngay>31 || thang < 1 || thang>12)
			cout << "\nNgay thang nam khong hop le! nhap lai.";
	} while (ngay < 1 || ngay>31 || thang < 1 || thang>12);
	
	do {
		cout << "\nNhap diem toan: ";
		cin >> toan;
	} while (toan < 0 || toan>10);
	do {
		cout << "\nNhap diem van: ";
		cin >> van;
	} while (van < 0 || van>10);
	do {
		cout << "\nNhap diem anh: ";
		cin >> anh;
	} while (anh < 0 || anh>10);
	
}

void Candidate::Xuat()
{
	cout << "\nHo ten: " << ten;
	cout << "\nMa so: " << maso;
	cout << "\nNgay sinh: " << ngay << "/" << thang << "/" << nam;
	cout << "\nDiem toan: " << toan;
	cout << "\nDiem van: " << van;
	cout << "\nDiem anh: " << anh;
}

float Candidate::TongDiem()
{
	return toan + van + anh;
}

