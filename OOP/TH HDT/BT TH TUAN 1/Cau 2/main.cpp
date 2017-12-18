#include "PhanSo2.h"

int main()
{
	PhanSo2 ps1, ps2;
	cout << "\nNhap Phan so 1: ";
	ps1.Nhap();
	ps1.RutGon();
	ps1.Xuat();
	cout << "\nNhap Phan so 2: ";
	ps2.Nhap();
	ps2.RutGon();
	ps2.Xuat();
	float ss = ps1.SoSanh(ps2);
	if (ss == -1) {
		cout << "\nPhan so 1 lon nhat! ";
		ps1.Xuat();
	}
	if (ss == 1) {
		cout << "\nPhan so 2 lon nhat! ";
		ps2.Xuat();
	}
	if (ss == 0) {
		cout << "\nPhan so 1 bang phan so 2 ";
		ps1.Xuat();
	}
	
	system("pause");
	return 0;
}