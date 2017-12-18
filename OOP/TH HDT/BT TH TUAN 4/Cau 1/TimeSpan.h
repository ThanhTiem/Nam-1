#pragma once
#include <iostream>
using namespace std;


class TimeSpan
{
private: 
	int gio, phut, giay;
public:
	TimeSpan();
	TimeSpan(int, int, int);
	TimeSpan(const TimeSpan&);
	~TimeSpan();
	void Nhap();
	void Xuat();
	TimeSpan TinhTong(TimeSpan);
	TimeSpan TinhHieu(TimeSpan);
	int SoSanhBang(TimeSpan);
	int SoSanh(TimeSpan);
};

