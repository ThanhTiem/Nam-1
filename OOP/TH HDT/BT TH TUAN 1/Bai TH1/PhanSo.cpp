#include "PhanSo.h"


PhanSo::PhanSo()
{
	tu = 0;
	mau = 1;
}
PhanSo::PhanSo(int ts, int ms)
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

int UCLN(int a, int b )
{
	a = abs(a);
	b = abs(b);
	while (a!=b) {
		if (a > b)
			a = a-b;
		else b=b-a;
	}
	return a;
}
void PhanSo::RutGon()
{ 
	int ucln = UCLN(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
}
void PhanSo::Xuat()
{
	if (mau < 0) {
		mau *= -1;
		tu *= -1;
	}
	cout << tu << "/" << mau;
}



