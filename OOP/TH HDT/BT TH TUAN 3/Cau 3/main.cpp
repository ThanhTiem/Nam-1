#include "DaGiac.h"
#include "Diem.h"

int main()
{
	DaGiac d;
	float x, y;
	d.Nhap();
	d.Xuat();
	cout << "\nNhap cac khoang cavh toa do can tinh tien: ";
	cin >> x >> y;
	cout << "\nToa do cac diem sau khi tinh tien la: ";
	d.TinhTien(x, y);
	d.Xuat();
	int beta;
	cout << "\nNhap vao goc can xoay: ";
	cin >> beta;
	cout << "\nToa do cac dinh sau khi xoay la: ";
	d.Xoay(beta);
	d.Xuat();

	system("pause");
	return 0;
}