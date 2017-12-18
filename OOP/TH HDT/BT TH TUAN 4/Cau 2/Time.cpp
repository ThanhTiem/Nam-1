#include "Time.h"



Time::Time()
{
}

Time::Time(int h, int p, int s)
{
	gio = h;
	phut = p;
	giay = s;
}

Time::Time(const Time &t)
{
	gio = t.gio;
	phut = t.phut;
	giay = t.giay;
}


Time::~Time()
{
}

void Time::Nhap()
{
	do {
		cout << "\nNhap vao lan luot gio, phut giay: ";
		cin >> gio >> phut >> giay;
		if ((gio < 0 || gio>23) || (phut < 0 || phut>60) || (giay < 0 || giay>60))
			cout << "\nThoi gian nhap khong hop le, vui long nhap lai. ";
	} while ((gio < 0 || gio>23) || (phut < 0 || phut>59) || (giay < 0 || giay>59));
}

void Time::Xuat()
{
	cout << gio << "h" << phut << "p" << giay << "s" << endl;
}

void Time::CongTime(int t)
{
	giay = giay + t;
	if (giay > 59) {
		phut += 1;
		giay = giay - 60;
	}
	if (phut > 59) {
		gio += 1;
		phut = 0;
	}
}

void Time::TruTime(int t)
{
	giay -= t;
	int n = t / 60;
	if (giay < 0) {
		giay = n * 60 + giay;
		phut = phut - 1;
		if (phut < 0) {
			phut = phut + 1;
			gio = gio - 1;
		}
	}
	if (n == 0) {
		giay = giay - t;
	}

}

void Time::ThemMotGiay()
{
	giay += 1;
	if (giay > 60) {
		giay -= 60;
		phut += 1;
		if (phut > 60) {
			phut -= 60;
			gio += 1;
		}
	}
	
}

void Time::BotMotGiay()
{
	if (giay == 0 && phut > 0) {
		giay = 59;
		phut -= 1;
	}
	if (giay == 0 && phut == 0) {
		phut = 59;
		gio -= 1;
	}
	if (giay > 0) {
		giay -= 1;
	}
}


