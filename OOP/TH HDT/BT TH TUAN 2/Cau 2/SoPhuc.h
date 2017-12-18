#pragma once
#include <iostream>
using namespace std;

class SoPhuc
{
private: 
	float thuc, ao;
public:
	SoPhuc();
	SoPhuc(int, int);
	~SoPhuc();
	void Nhap();
	void Xuat();
	SoPhuc TinhTong(SoPhuc);
	SoPhuc TinhHieu(SoPhuc);
	SoPhuc TinhTich(SoPhuc);
	SoPhuc TinhThuong(SoPhuc);
};

