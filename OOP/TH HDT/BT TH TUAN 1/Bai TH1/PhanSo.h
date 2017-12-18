#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
private:
	int tu, mau;
public:
	PhanSo();
	PhanSo(int, int);
	~PhanSo();
	void Nhap();
	void Xuat();
	void RutGon();
};

