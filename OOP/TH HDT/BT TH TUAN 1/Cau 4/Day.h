#pragma once
#include <iostream>
using namespace std;
class Day
{
private:
	int ngay, thang, nam;
public:
	Day();
	~Day();
	void Nhap();
	void Xuat();
	Day NextDay(const Day &);

};

