#include "DE.h"



DE::DE()
{
	tiengkeu = "Dede!";
}

void DE::nhap()
{
	cout << endl << "Nhap so luong con DE ban dau:";
	cin >> this->condau;
	getCon();
	getSua();
}
void DE::xuat()
{
	cout << endl << "So luong con DE ban dau:" << condau
		<< endl << "So luong DE con sinh ra:" << concai
		<< endl << "So luong sua DE:" << sua
		<< endl << "Tieng keu cua DE:" << tiengkeu;
	fstream f;
	f.open("hjhj.txt", ios_base::out);
	f << endl << "So luong DE ban dau:" << condau
		<< endl << "So luong DE sinh ra:" << concai
		<< endl << "So luong sua:" << sua
		<< endl << "Tieng keu:" << tiengkeu;
	f.close();
}
int DE::getSua()
{
	for (int i = 0; i < (condau + concai); i++) {
		sua += rand() % 20 + 0;
	}
	return sua;
}
DE::~DE() {}
