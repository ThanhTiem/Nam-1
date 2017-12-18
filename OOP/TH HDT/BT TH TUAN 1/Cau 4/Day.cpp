#include "Day.h"



Day::Day()
{
}


Day::~Day()
{
}

void Day::Nhap()
{
	int x;
	do
	{
		cout << "Day: ";
		cin >> ngay;
		cout << "Month: ";
		cin >> thang;
		cout << "Year: ";
		cin >> nam;

		switch (thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			x = 31;
			break;
		case 4: case 6: case 9: case 11:
			x = 30;
			break;
		case 2:
			if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
				x = 29;
			else
				x = 28;
			break;
		default: x = 0;
		}
		if (x == 0 || ngay <= 0 || ngay > x)
			cout << "\nngay khong hop le! vui long nhap lai. " << endl;
	} while (x == 0 || ngay <= 0 || ngay > x);
}

void Day::Xuat()
{
	cout << ngay << " / " << thang << " / " << nam << endl;
}

Day Day::NextDay(const Day &a)
{
	int x;
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		x = 31;
		break;
	case 4: case 6: case 9: case 11:
		x = 30;
		break;
	case 2:
		if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
			x = 29;
		else
			x = 28;
		break;
	}
	if (ngay == x)
	{
		ngay = 1;
		if (thang == 12)
		{
			thang = 1;
			nam++;
		}
		else
			thang++;
	}
	else
		ngay++;
	return a;
}
