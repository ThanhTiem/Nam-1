#include "PhanSo.h"



PhanSo::PhanSo()
{
	tu = 0;
	mau = 1;
}

PhanSo::PhanSo(float ts, float ms)
{
	tu = ts;
	mau = ms;
}


PhanSo::~PhanSo()
{
}

void PhanSo::Nhap()
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

void PhanSo::Xuat()
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
void PhanSo::RutGon()
{
	int ucln = UCLN(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
}

PhanSo PhanSo::TinhTong(PhanSo ps)
{
	PhanSo Tong;
	Tong.tu = tu*ps.mau + mau*ps.tu;
	Tong.mau = mau*ps.mau;
	return Tong;
}

PhanSo PhanSo::TinhHieu(PhanSo ps)
{
	PhanSo Hieu;
	Hieu.tu = tu*ps.mau - mau*ps.tu;
	Hieu.mau = mau*ps.mau;
	return Hieu;
}

PhanSo PhanSo::TinhTich(PhanSo ps)
{
	PhanSo Tich;
	Tich.tu = tu*ps.tu;
	Tich.mau = mau*ps.mau;
	return Tich;
}

PhanSo PhanSo::TinhThuong(PhanSo ps)
{
	PhanSo Thuong;
	Thuong.tu = tu*ps.mau;
	Thuong.mau = mau*ps.tu;
	return Thuong;
}
