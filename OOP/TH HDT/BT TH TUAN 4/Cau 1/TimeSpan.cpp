#include "TimeSpan.h"



TimeSpan::TimeSpan()
{
	gio = phut = giay = 0;
}

TimeSpan::TimeSpan(int h, int p, int s)
{
	gio = h;
	phut = p;
	giay = s;
}

TimeSpan::TimeSpan(const TimeSpan &t)
{
	gio = t.gio;
	phut = t.phut;
	giay = t.giay;
}


TimeSpan::~TimeSpan()
{
}

void TimeSpan::Nhap()
{
	do {
		cout << "\nNhap vao lan luot gio, phut giay: ";
		cin >> gio >> phut >> giay;
		if ((gio < 0 || gio>23) || (phut < 0 || phut>60) || (giay < 0 || giay>60))
			cout << "\nThoi gian nhap khong hop le, vui long nhap lai. ";
	} while ((gio < 0 || gio>23) || (phut < 0 || phut>60) || (giay < 0 || giay>60));
}

void TimeSpan::Xuat()
{
	cout << gio << "h" << phut << "p" << giay << "s" << endl;
}

TimeSpan TimeSpan::TinhTong(TimeSpan t)
{
	TimeSpan Tong;
	Tong.gio = gio + t.gio;
	Tong.phut = phut + t.phut;
	Tong.giay = giay + t.giay;
	if (Tong.giay > 60) {
		Tong.phut += 1;
		Tong.giay = Tong.giay % 60;
	}
	if (Tong.phut > 60) {
		Tong.gio += 1;
		Tong.phut = Tong.phut % 60;
	}
	return Tong;
}

TimeSpan TimeSpan::TinhHieu(TimeSpan t)
{
	TimeSpan Hieu;
	int a = giay + phut * 60 + gio * 3600;
	int b = t.giay + t.phut * 60 + t.gio * 3600;
	if (a == b)
		Hieu.giay = Hieu.phut = Hieu.gio = 0;
	if (a > b) {
		if (giay < t.giay) {
			phut = phut - 1;
			giay = giay + 60;
		}
		if (phut < t.phut) {
			gio = gio - 1;
			phut = phut + 60;
		}
		Hieu.gio = gio - t.gio;
		Hieu.phut = phut - t.phut;
		Hieu.giay = giay - t.giay;
	}
	else {
		if (t.giay < giay) {
			phut = phut - 1;
			giay = giay + 60;
		}
		if (t.phut < phut) {
			gio = gio - 1;
			phut = phut + 60;
		}
		Hieu.gio = t.gio - gio;
		Hieu.phut = t.phut - phut;
		Hieu.giay = t.giay - giay;
	}
	return Hieu;
}

int TimeSpan::SoSanhBang(TimeSpan t)
{
	if (gio == t.gio&&phut == t.phut&&giay == t.giay)
		return 1;
	return -1;
}

int TimeSpan::SoSanh(TimeSpan t)
{
	if (gio > t.gio)
		return 1;
	else {
		if(gio ==t.gio){
			if (phut > t.phut)
				return 1;
			else{
				if(phut==t.phut){
					if (giay > t.giay)
						return 1;
					}
				}
			}
		}
}
