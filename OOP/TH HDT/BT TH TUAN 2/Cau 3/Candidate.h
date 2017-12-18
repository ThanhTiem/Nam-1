#pragma once
#include <iostream>
#include <string>
using namespace std;
class Candidate
{
private:
	int maso;
	char ten[100];
	int ngay, thang, nam;
	float toan, van, anh;
public:
	Candidate();
	~Candidate();
	void Nhap();
	void Xuat();
	float TongDiem();
};

