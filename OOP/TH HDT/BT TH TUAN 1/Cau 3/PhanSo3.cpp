#include "PhanSo3.h"



PhanSo3::PhanSo3()
{
	tu = 0;
	mau = 1;
}

PhanSo3::PhanSo3(float ts, float ms)
{
	tu = ts;
	mau = ms;
}


PhanSo3::~PhanSo3()
{
}

void PhanSo3::Nhap()
{
	cout << "\nNhap tu: ";
	cin >> tu;
	do {
		cout << "\nNhap mau: ";
		cin >> mau;
		if (mau == 0) {
			cout << "\nNhap mau sai, nhap lai!!";
		}
	} while (mau == 0);
}

void PhanSo3::Xuat()
{
	if (mau < 0) {
		mau *= -1;
		tu *= -1;
	}
	cout << tu << "/" << mau;
}
int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b) {
		if (a > b)
			a = a - b;
		else b = b - a;
	}
	return a;
}
void PhanSo3::RutGon()
{
	int ucln = UCLN(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
}

PhanSo3 PhanSo3::TinhTong(PhanSo3 ps)
{ 
	PhanSo3 Tong;
	Tong.tu = tu*ps.mau + mau*ps.tu;
	Tong.mau = mau*ps.mau;
	return Tong;
}

PhanSo3 PhanSo3::TinhHieu(PhanSo3 ps)
{
	PhanSo3 Hieu;
	Hieu.tu = tu*ps.mau - mau*ps.tu;
	Hieu.mau = mau*ps.mau;
	return Hieu;
}

PhanSo3 PhanSo3::TinhTich(PhanSo3 ps)
{
	PhanSo3 Tich;
	Tich.tu = tu*ps.tu;
	Tich.mau = mau*ps.mau;
	return Tich;
}

PhanSo3 PhanSo3::TinhThuong(PhanSo3 ps)
{
	PhanSo3 Thuong;
	Thuong.tu = tu*ps.mau;
	Thuong.mau = mau*ps.tu;
	return Thuong;
}
