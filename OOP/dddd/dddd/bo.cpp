#include "bo.h"



bo::bo()
{
	tiengkeu = "Bobo!";
}


bo::~bo()
{
}
void bo::nhap()
{
	cout << endl << "Nhap so luong con bo ban dau:";
	cin >> this->condau;
	getCon();
	getSua();
}
void bo::xuat()
{
	cout << endl << "So luong con bo ban dau:" << condau
		<< endl << "So luong bo con sinh ra:" << concai
		<< endl << "So luong sua bo:" << sua
		<< endl << "Tieng keu cua bo:" << tiengkeu;
	fstream f;
	f.open("fileout.txt", ios_base::out);
	f << endl << "So luong con ban dau:" << condau
		<< endl << "So luong con sinh ra:" << concai
		<< endl << "So luong sua:" << sua
		<< endl << "Tieng keu:" << tiengkeu;
	f.close();
}
int bo::getSua()
{
	for (int i = 0; i < (condau + concai); i++) {
		sua += rand() % 20 + 0;
	}
	return sua;
}