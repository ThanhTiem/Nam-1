#pragma once
#include <string>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
class giasuc
{
protected:
	int condau;
	int concai;
	int sua;
	string tiengkeu;
public:
	giasuc();
	virtual void nhap();
	virtual void xuat();
	virtual int getSua();
	int getCon();
};
