#pragma once
#include <iostream>
#include "DIEM.h"
using namespace std;

class TamGiac
{
private: 
	Diem A, B, C;
public:
	TamGiac();
	TamGiac(Diem, Diem, Diem);
	~TamGiac();
	void Nhap();
	void Xuat();
	void TinhTien(float, float);
	void Xoay(int);
};

