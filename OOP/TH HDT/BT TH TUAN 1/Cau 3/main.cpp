#include "PhanSo3.h"
int main()
{
	PhanSo3 ps1, ps2;
	cout << "\nNhap phan so 1: ";
	ps1.Nhap();
	ps1.RutGon();
	ps1.Xuat();
	cout << "\nNhap phan so 2: ";
	ps2.Nhap();
	ps2.RutGon();
	ps2.Xuat();
	PhanSo3 Tong = ps1.TinhTong(ps2);
	PhanSo3 Hieu = ps1.TinhHieu(ps2);
	PhanSo3 Tich = ps1.TinhTich(ps2);
	PhanSo3 Thuong = ps1.TinhThuong(ps2);
	cout << "\nTong la: ";
	Tong.Xuat();
	cout << "\nHieu la: ";
	Hieu.Xuat();
	cout << "\nTich la: ";
	Tich.Xuat();
	cout << "\nThuong la: ";
	Thuong.Xuat();
	system("pause");
	return 0;
}