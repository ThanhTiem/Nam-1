#include "TestCandidate.h"



TestCandidate::TestCandidate()
{
}


TestCandidate::~TestCandidate()
{
}

void TestCandidate::Nhap()
{
	cout << "\nNhap vao so luong thi sinh: ";
	cin >> soluong;
	for (int i = 0; i < soluong; i++) {
		cout << "\nNhap thi sinh thu " << i + 1 << ": ";
		ts[i].Nhap();
	}
}

void TestCandidate::Tim()
{
	for (int i = 0; i < soluong; i++) {
		float x = ts[i].TongDiem();
		if (x > 15)
			ts[i].Xuat();
	}
}
