#include "TamGiac.h"
#include "DIEM.h"


TamGiac::TamGiac()
{
	A.Setter_Diem(0, 0);
	B.Setter_Diem(0, 1);
	C.Setter_Diem(1, 0);
}

TamGiac::TamGiac(Diem X, Diem Y, Diem Z)
{
	A.Setter_Diem(X);
	B.Setter_Diem(Y);
	C.Setter_Diem(Z);
}


TamGiac::~TamGiac()
{
}

void TamGiac::Nhap()
{
	cout << "\nNhap toa do diem A: ";
	A.Nhap();
	cout << "\nNhap toa do diem B: ";
	B.Nhap();
	cout << "\nNhap toa do diem C: ";
	C.Nhap();
}

void TamGiac::Xuat()
{
	cout << "\nTam giac ABC: ";
	A.Xuat();
	B.Xuat();
	C.Xuat();
}

void TamGiac::TinhTien(float x, float y)
{
	A.Setter_Diem(A.Getter_Hoanh() + x, A.Getter_Tung() + y);
	B.Setter_Diem(B.Getter_Hoanh() + x, B.Getter_Tung() + y);
	C.Setter_Diem(C.Getter_Hoanh() + x, C.Getter_Tung() + y);
}

void TamGiac::Xoay(int phi)
{
	int anpha = (phi * 2 * 3.14) / 180;
	A.Xoay(anpha);
	B.Xoay(anpha);
	C.Xoay(anpha);
}
