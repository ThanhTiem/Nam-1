#pragma once
#include <iostream>
#include <string>
using namespace std;
class HocSinh
{
private:
	char ten[100];
	float toan, van;
public:
	HocSinh();
	~HocSinh();
	void Nhap();
	void Xuat();
	//void TinhDiemTB();
};

