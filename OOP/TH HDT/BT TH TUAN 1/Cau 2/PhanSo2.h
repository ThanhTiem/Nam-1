#pragma once
#include <iostream>
using namespace std;
class PhanSo2
{
private:
	float tu, mau;
public:
	PhanSo2();
	PhanSo2(int, int);
	~PhanSo2();
	void Nhap();
	void Xuat();
	void RutGon();
	int SoSanh(const PhanSo2);
};

