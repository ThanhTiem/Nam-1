#pragma once
#include <iostream>
using namespace std;


class Time
{
private:
	int gio, phut, giay; 
public:
	Time();
	Time(int, int, int);
	Time(const Time&);
	~Time();
	void Nhap();
	void Xuat();
	void CongTime(int);
	void TruTime(int);
	void ThemMotGiay();
	void BotMotGiay();
};

