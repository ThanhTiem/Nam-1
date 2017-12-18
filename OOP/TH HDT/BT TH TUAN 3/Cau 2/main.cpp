#include "DIEM.h"
#include "TamGiac.h"

int main()
{
	TamGiac t;
	float x, y;
	t.Nhap();
	cout << "\nToa do lan luot cac diem A, B, C cua tam giac: ";
	t.Xuat();
	cout << "\nNhap khoang cach cac diem can tinh tien: ";
	cin >> x >> y;
	cout << "\nToa do  lan luot cac diem A,B,C cuaTAM GIAC sau khi tinh tien: ";
	t.TinhTien(x, y);
	t.Xuat();
	int beta;
	cout << "\nNhap goc can xoay: ";
	cin >> beta;
	t.Xoay(beta);
	cout << "\nToa do cac diem sau khi xoay la: ";
	t.Xuat();
	system("pause");
	return 0;
}