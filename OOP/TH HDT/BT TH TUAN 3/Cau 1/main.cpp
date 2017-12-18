#include "Diem.h"

int main()
{
	Diem d;
	float x, y;
	d.Nhap();
	d.Xuat();
	cout << "\nNhap khoang cach diem ban muon tinh tien: ";
	cout << "\nKhoang cach X: ";
	cin >> x;
	cout << "\nKhoang cach Y: ";
	cin >> y;
	d.TinhTien(x, y);
	cout << "\nToa do sau khi tinh tien la: ";
	d.Xuat();
	system("pause");
	return 0;
}