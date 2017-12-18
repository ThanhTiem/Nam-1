#pragma once
#include <iostream>
using namespace std;

class PhanSo3
{
private:
	float tu, mau;
public:
	PhanSo3();
	PhanSo3(float, float);
	~PhanSo3();
	void Nhap();
	void Xuat();
	void RutGon();
	PhanSo3 TinhTong(PhanSo3);
	PhanSo3 TinhHieu(PhanSo3);
	PhanSo3 TinhTich(PhanSo3);
	PhanSo3 TinhThuong(PhanSo3);
};

