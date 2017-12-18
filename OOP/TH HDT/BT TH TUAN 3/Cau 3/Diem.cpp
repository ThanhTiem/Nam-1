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
		cout << "\nToa do: " << "(" << hoanh << "," << tung << ")";
}

float Diem::Getter_Hoanh()
{

	return hoanh;
}

float Diem::Setter_Hoanh(float x)
{
	hoanh = x;
	return 1;
}

float Diem::Getter_Tung()
{

	return tung;
}

float Diem::Setter_Tung(float y)
{
	tung = y;
	return 1;
}

void Diem::TinhTien(float x, float y)
{
	hoanh += x;
	tung += y;
}

float Diem::Setter_Diem(float x, float y)
{
	hoanh = x;
	tung = y;
	return 1;
}

float Diem::Setter_Diem(Diem p)
{
	hoanh = p.hoanh;
	tung = p.tung;
	return 1;
}

void Diem::Xoay(float anpha)
{
	hoanh = hoanh*cos(anpha) - tung*sin(anpha);
	tung = hoanh*sin(anpha) + tung*cos(anpha);
}



