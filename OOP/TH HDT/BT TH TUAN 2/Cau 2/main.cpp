#include "SoPhuc.h"

int main()
{
	SoPhuc sp1, sp2;
	cout << "\nNhap So phuc 1: ";
	sp1.Nhap();
	sp1.Xuat();
	cout << "\nNhap so phuc 2: ";
	sp2.Nhap();
	sp2.Xuat();
	SoPhuc Tong = sp1.TinhTong(sp2);
	SoPhuc Hieu = sp1.TinhHieu(sp2);
	SoPhuc Tich = sp1.TinhTich(sp2);
	SoPhuc Thuong = sp1.TinhThuong(sp2);
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