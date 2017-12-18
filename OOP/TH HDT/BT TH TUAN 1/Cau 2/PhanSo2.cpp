#include "PhanSo2.h"



PhanSo2::PhanSo2()
{
	tu = 0;
	mau = 1;
}

PhanSo2::PhanSo2(int ts, int ms)
{
	tu = ts;
	mau = ms;
}

PhanSo2::~PhanSo2()
{
}

void PhanSo2::Nhap()
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

void PhanSo2::Xuat()
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
void PhanSo2::RutGon()
{
	int ucln = UCLN(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
}
int PhanSo2::SoSanh(const PhanSo2 x)
{
	float a = tu / mau;
	float b = x.tu / x.mau;
	if (a > b)
		return -1;
	if (a < b)
		return 1;
	if (a == b)
		return 0;
}


