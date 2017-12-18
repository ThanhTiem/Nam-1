#pragma once
#include <iostream>
#include "Candidate.h"
class TestCandidate
{
private: 
	int soluong;
	Candidate ts[1000];
public:
	TestCandidate();
	~TestCandidate();
	void Nhap();
	void Tim();
};

