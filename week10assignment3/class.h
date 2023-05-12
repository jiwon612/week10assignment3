#pragma once
#include <fstream>
using namespace std;

class lol {
public:
	// constructor
	lol() {};
	lol(int i1, int i2, float f1, float f2, float f3, float f4, int i3);
	// deconstructor
	~lol() { out.close(); }
	// member data
	ofstream out;
	ifstream in;
	int N1, N2, m, nn, * n;
	float a, b, x0, dx, * fx;
	// member function
	void isum();
	void fsum();
	void WriteData(char* ff);
};
