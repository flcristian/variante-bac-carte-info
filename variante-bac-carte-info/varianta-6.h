#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << i + (j - 1) * 5 << " ";
			if (j == 5) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1 
// Sa se determine lungimea maxima a unui cuvant dintr-un
// sir de caractere citit de la tastatura si numarul de cuvinte
// cu aceasta lungime.

void spargereCuvinte(char s[], char cuvinte[100][100], int& n) {
	n = 0;
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[n], a);
		n++;
		a = strtok(NULL, " ");
	}
}

void frecventaLungimeCuvinte(char cuvinte[100][100], int f[], int n) {
	for (int i = 0; i < n; i++) {
		f[strlen(cuvinte[i])]++;
	}
}

int maxLenght(int f[]) {
	int max = 0;
	for (int i = 0; i < 30; i++) {
		if (f[i] > 0 && i > max) {
			max = i;
		}
	}
	return max;
}

void rezolvareSub3Problema1() {
	char s[100];
	cin.getline(s, 100);

	char cuvinte[100][100];
	int n;
	spargereCuvinte(s, cuvinte, n);
	int f[30]{};
	frecventaLungimeCuvinte(cuvinte, f, n);

	int max = maxLenght(f);
	cout << max << " " << f[max] << endl;
}

// Problema 2
// Subprogramul divizor are doi paramteri :
// n - numar natural
// a - un tablou unidimensional care memoreaza n numere naturale
// Subprogramul returneaza cel mai mare divizor comun al celor n numere.

void citireProblema2(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		if (b > a) {
			b = b - a;
		}
	}
	return a;
}

int divizor(int a[], int n) {
	int d = a[0];
	for (int i = 1; i < n; i++) {
		d = cmmdc(d, a[i]);
	}
	return d;
}

void rezolvareSub3Problema2() {
	int a[100], n;
	citireProblema2(a, n);

	cout << divizor(a, n) << endl;
}

// Problema 3
// Un numar este p-compus daca se poate scrie ca suma de
// p numere consecutive.
// Sa se afiseze pe ecran, la fiecare element al vectorului citit
// primul numar din aceasta suma, sau NU daca nu poate fi scris astfel.

// <=> Fisier Citire <=>
// Prima linie : numarul p
// A doua linie : elementele vectorului

void citireProblema3(int x[], int& n, int& p) {
	ifstream f("input.txt");
	f >> p;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void nCompuse(int x[], int n, int p) {
	int k = p / 2;
	if (p % 2 == 1) {
		for (int i = 0; i < n; i++) {
			if (x[i] % p == 0) {
				cout << x[i] / p - k;
			}
			else {
				cout << "NU";
			}
			cout << " ";
		}
	}
	else {
		int j = k - 1;
		for (int i = 0; i < n; i++) {
			if (x[i] % p == k) {
				cout << x[i] / p - j;
			}
			else {
				cout << "NU";
			}
			cout << " ";
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n, p;
	citireProblema3(x, n, p); 
	nCompuse(x, n, p);
}