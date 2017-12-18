#include "Day.h"

int main()
{
	Day a;
	a.Nhap();
	Day next = a.NextDay(a);
	cout << "\nNgay tiep theo la: ";
	a.Xuat();

	system("pause");
	return 0;
}