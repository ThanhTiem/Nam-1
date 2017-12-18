#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
private:
	float tu, mau;
public:
	PhanSo();
	PhanSo(float, float);
	~PhanSo();
	void Nhap();
	void Xuat();
	void RutGon();
	PhanSo TinhTong(PhanSo);
	PhanSo TinhHieu(PhanSo);
	PhanSo TinhTich(PhanSo);
	PhanSo TinhThuong(PhanSo);
};

