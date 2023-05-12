#include "class.h"
#include <iostream>
#include <fstream>
using namespace std;

// constructor
lol::lol(int i1, int i2, float f1, float f2, float f3, float f4, int i3) {
	N1 = i1; N2 = i2; a = f1; b = f2; x0 = f3; dx = f4; m = i3;
	n = nullptr; fx = nullptr; nn = N2 - N1 + 1;
}
// member function
void lol::isum() {
	if (n == nullptr) n = new int[nn];
	for (int i = 0; i < nn; i++)
		n[i] = N1 + i;
}
void lol::fsum() {
	if (fx == nullptr) fx = new float[m];
	float x = x0;
	for (int i = 0; i < m + 1; i++) {
		x += dx;
		fx[i] = a * x + b;
	}
}

void lol::WriteData(char* ff) {
	isum(); fsum();
	out = ofstream(ff, ios::binary | ios::out);
	in = ifstream(ff, ios::binary | ios::out);
	out.write((char*)&N1, sizeof(int));
	out.write((char*)&N2, sizeof(int));
	out.write((char*)&a, sizeof(float));
	out.write((char*)&b, sizeof(float));
	out.write((char*)&x0, sizeof(float));
	out.write((char*)&dx, sizeof(float));
	out.write((char*)&m, sizeof(int));
	out.write((char*)n, nn * sizeof(int));
	out.write((char*)fx, m * sizeof(float));
}

int main() {
	lol* akali, * amumu, * annie, * ashe;
	akali = new lol(5, 10, 2, 3, -5, 0.1, 10);
	amumu = new lol(7, 100, -3.5, 4, 100, 10, 15);
	annie = new lol(12, 17, 0.01, 0.2, 1.5, 0.08, 20);
	ashe = new lol(10, 20, 4.2, -5.3, 2.1, 0.2, 5);

	akali->WriteData((char*)"akali.dat"); amumu->WriteData((char*)"amumu.dat");
	annie->WriteData((char*)"annie.dat"); ashe->WriteData((char*)"ashe.dat");
	akali->~lol(); amumu->~lol();
	annie->~lol(); ashe->~lol();

	float ashe1[10], akali1[10], annie1[10], amumu1[10];
	ifstream xx((char*)"akali.dat", ios::binary | ios::in);
	xx.read((char*)akali1, sizeof(akali1));
	xx.close();

	ifstream xx1((char*)"ashe.dat", ios::binary | ios::in);
	xx1.read((char*)ashe1, sizeof(ashe1));
	xx1.close();

	ifstream xx2((char*)"annie.dat", ios::binary | ios::in);
	xx2.read((char*)annie1, sizeof(annie1));
	xx2.close();

	ifstream xx3((char*)"amumu.dat", ios::binary | ios::in);
	xx3.read((char*)amumu1, sizeof(amumu1));
	xx3.close();

	for (int i = 0; i < 10; i++) {
		cout << akali1[i] << endl;
	}

	for (int i = 0; i < 10; i++) {
		cout << ashe1[i] << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << annie1[i] << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << amumu1[i] << endl;
	}
	return 1;
}


