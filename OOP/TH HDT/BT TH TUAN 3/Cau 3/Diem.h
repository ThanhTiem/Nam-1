#pragma once
#include <iostream>
#include <math.h>
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
	float Getter_Hoanh();
	float Setter_Hoanh(float);
	float Getter_Tung();
	float Setter_Tung(float);
	void TinhTien(float, float);
	float Setter_Diem(float, float);
	float Setter_Diem(Diem);
	void Xoay(float);
};
