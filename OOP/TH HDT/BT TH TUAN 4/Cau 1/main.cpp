#include "TimeSpan.h"

int main()
{
	TimeSpan t1, t2;
	cout << "\nNhap vao thoi gian 1: ";
	t1.Nhap();
	cout << "\nNhap vao thoi gian 2: ";
	t2.Nhap();
	cout << "\nThoi gian ban nhap: ";
	t1.Xuat();
	t2.Xuat();
	TimeSpan Tong = t1.TinhTong(t2);
	TimeSpan Hieu = t1.TinhHieu(t2);
	cout << "\nTong: ";
	Tong.Xuat();
	cout << "\nHieu: ";
	Hieu.Xuat();

	if (t1.SoSanhBang(t2) == 1)
		cout << "\nT1 = T2.";
	else
		cout << "\nT1 Khac T2.";
	if (t1.SoSanh(t2) == 1)
		cout << "\nT1 > T2";
	else
		cout << "\nT1 < T2";
	system("pause");
	return 0;
}