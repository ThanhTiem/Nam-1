#include "SoPhuc.h"



SoPhuc::SoPhuc()
{
	thuc = 0;
	ao = 0;
}

SoPhuc::SoPhuc(int th, int a)
{
	thuc = th;
	ao = a;
}


SoPhuc::~SoPhuc()
{
}

void SoPhuc::Nhap()
{
	cout << "\nNhap phan thuc: ";
	cin >> thuc;
	cout << "\nNhap phan ao: ";
	cin >> ao;
}

void SoPhuc::Xuat()
{
	cout << thuc << " + " << ao << "i";
}

SoPhuc SoPhuc::TinhTong(SoPhuc sp)
{
	SoPhuc Tong;
	Tong.thuc = thuc + sp.thuc;
	Tong.ao = ao + sp.ao;
	return Tong;
}

SoPhuc SoPhuc::TinhHieu(SoPhuc sp)
{
	SoPhuc Hieu;
	Hieu.thuc = thuc + sp.thuc;
	Hieu.ao = ao + sp.ao;
	return Hieu;
}

SoPhuc SoPhuc::TinhTich(SoPhuc sp)
{
	SoPhuc Tich;
	Tich.thuc = thuc*sp.thuc - ao*sp.ao;
	Tich.ao = thuc*sp.ao + ao*sp.thuc;
	return Tich;
}

SoPhuc SoPhuc::TinhThuong(SoPhuc sp)
{
	SoPhuc Thuong;
	Thuong.thuc = (thuc*sp.thuc + ao*sp.ao) / (sp.thuc*sp.thuc + sp.ao*sp.ao);
	Thuong.ao = (sp.thuc*ao - thuc*sp.ao) / (sp.thuc*sp.thuc + sp.ao*sp.ao);
	return Thuong;
}


