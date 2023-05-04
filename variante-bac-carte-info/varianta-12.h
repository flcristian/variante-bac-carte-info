#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 3

// Problema 1
// ? ? ? ?

void rezolvareSub3Problema1() {

}

// Problema 2
// Sa se scrie un subprogram care afiseaza
// pe ecran perechile de numere x - y, unde
// cel mai mare multiplu comun este parametrul m.

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

int cmmmc(int a, int b) {
	return (a * b) / cmmdc(a, b);
}

void perechi(int m) {
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			if (cmmmc(i, j) == m && i != j) {
				cout << i << " " << j << endl;
			}
		}
	}
}

void rezolvareSub3Problema2() {
	perechi(6);
}

// Problema 3
// Sa se afiseze pe ecran elementele dintr-un
// vector citit din fisier cu numar maxim de
// aparitie.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void frecventa(int x[], int f[], int n) {
	for (int i = 0; i < n; i++) {
		f[x[i] + 10]++;
	}
}

void maxAparitii(int f[], int v[], int& d) {
	d = 0;
	int max = 0;
	for (int i = 0; i < 20; i++) {
		if (f[i] > max) {
			max = f[i];
			d = 0;
		}
		if (f[i] == max) {
			v[d] = i - 10;
			d++;
		}
	}
}

void afisare(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	int f[40]{};
	frecventa(x, f, n);
	int v[100], d;
	maxAparitii(f, v, d);
	afisare(v, d);
}