#include "giasuc.h"



giasuc::giasuc()
{
	condau = 0;
	concai = 0;
	tiengkeu = "";
	sua = 0;
}

void giasuc::nhap()
{
	cout << endl << "Nhap so luong con ban dau:";
	cin >> this->condau;
	this->getCon();
	this->getSua();
}
void giasuc::xuat()
{
	cout << endl << "So luong con ban dau:" << condau
		<< endl << "So luong con sinh ra:" << concai
		<< endl << "So luong sua:" << sua
		<< endl << "Tieng keu:" << tiengkeu;
	fstream f;
	f.open("fileout.txt", ios_base::out);
	f << endl << "So luong con ban dau:" << condau
		<< endl << "So luong con sinh ra:" << concai
		<< endl << "So luong sua:" << sua
		<< endl << "Tieng keu:" << tiengkeu;
	f.close();
}
int giasuc::getSua()
{
	if (tiengkeu == "Bobo!") {
		for (int i = 0; i < (condau + concai); i++) {
			sua += rand() % 20 + 0;
		}
	}
	if (tiengkeu == "Cuucuu!") {
		for (int i = 0; i < (condau + concai); i++) {
			sua += rand() % 5 + 0;
		}

	}
	if (tiengkeu == "Dede!") {
		for (int i = 0; i < (condau + concai); i++) {
			sua += rand() % 10 + 0;
		}
	}
	return sua;
}
int giasuc::getCon()
{
	srand((int)time(NULL));
	for (int i = 0; i < condau; i++) {
		concai += rand() % 3 + 1;
	}
	return concai;
}
