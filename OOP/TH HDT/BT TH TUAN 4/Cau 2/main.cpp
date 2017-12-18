#include "Time.h"
#

int main()
{
	Time t;
	int a;
	cout << "\nNhap vao thoi gian: ";
	t.Nhap();
	cout << "\nThoi gian vua nhap: ";
	t.Xuat();
	cout << "\nNhap vao so giay ban can them / bot:";
	cin >> a;
	cout << "\nTong: ";
	t.CongTime(a);
	t.Xuat();
	cout << "\nHieu: ";
	t.TruTime(a);
	t.Xuat();
	cout << "\nSau khi them mot giay: ";
	t.ThemMotGiay();
	t.Xuat();
	cout << "\nSau khi bot mot giay: ";
	t.BotMotGiay();
	t.Xuat();
	system("pause");
	return 0;
}