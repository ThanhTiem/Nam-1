#include "Diem.h"



Diem::Diem()
{
	hoanh = 0;
	tung = 0;
}

Diem::Diem(float x, float y)
{
	hoanh = x;
	tung = y;
}


Diem::~Diem()
{
}

void Diem::Nhap()
{
	cout << "\nNhap hoanh do: ";
	cin >> hoanh;
	cout << "\nNhap tung do: ";
	cin >> tung;

}

void Diem::Xuat()
{
	cout << "\nToa do diem la: " << "(" << hoanh << "," << tung << ")";
}

void Diem::Getter_Hoanh(float x)
{
	hoanh = x;
}

float Diem::Setter_Hoanh()
{
	return hoanh;
}

void Diem::Getter_Tung(float y)
{
	tung = y;
}

float Diem::Setter_Tung()
{
	return tung;
}

void Diem::TinhTien(float x, float y)
{
	hoanh += x;
	tung += y;
}

