#pragma once
#include <iostream>
using namespace std;

class Diem
{
private:
	float hoanh, tung;
public:
	Diem();
	Diem(float, float);
	~Diem();
	void Nhap();
	void Xuat();
	void Getter_Hoanh(float);
	float Setter_Hoanh();
	void Getter_Tung(float);
	float Setter_Tung();
	void TinhTien(float, float);
};

