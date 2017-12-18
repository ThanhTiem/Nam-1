#include "DaGiac.h"



DaGiac::DaGiac()
{
	for (int i = 0; i < n; i++) {
		cout << "\nNhap toa do diem thu " << i + 1 << ": ";
		Dinh[i].Setter_Diem(0, 0);
	}
}

DaGiac::DaGiac(Diem Dinh[])
{
	for (int i = 0; i < n; i++) {
		Dinh[i].Setter_Diem(Dinh[i]);
	}
}


DaGiac::~DaGiac()
{
}

void DaGiac::Nhap()
{
	cout << "\nNhap vao so dinh cua da giac: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap vao dinh thu " << i + 1 << ": ";
		Dinh[i].Nhap();
	}
}

void DaGiac::Xuat()
{
	cout << "\nToa do cac diem cua da giac la: ";
	for (int i = 0; i < n; i++) {
		Dinh[i].Xuat();
	}
}

void DaGiac::TinhTien(float x, float y)
{
	for (int i = 0; i < n; i++) {
		Dinh[i].Setter_Diem(Dinh[i].Getter_Hoanh() + x, Dinh[i].Getter_Tung() + y);
	}
}

void DaGiac::Xoay(float phi)
{
	float anpha = (phi * 2 * 3.14) / 180;
	for (int i = 0; i < n; i++) {
		Dinh[i].Xoay(anpha);
	}
}

