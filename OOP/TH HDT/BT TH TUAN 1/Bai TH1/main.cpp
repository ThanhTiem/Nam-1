#include "PhanSo.h"

int main()
{
	PhanSo ps;
	ps.Nhap();
	cout << "\nPhan so ban nhap: ";
	ps.Xuat();
	cout << "\nSau khi rut gon: ";
	ps.RutGon();
	ps.Xuat();
	system("pause");
	return 0;
}