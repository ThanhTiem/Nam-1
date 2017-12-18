#pragma once
#include "Diem.h"
class DaGiac
{
private:
	int n;
	Diem Dinh[100];
public:
	DaGiac();
	DaGiac(Diem[]);
	~DaGiac();
	void Nhap();
	void Xuat();
	void TinhTien(float, float);
	void Xoay(float);
};

