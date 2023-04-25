#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			cout << (i + j) % 5 << " ";

			// Trebuie compeltat in acest "for"
			// v v v

			if (j == 5) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1
// Se considera un sir de caractere, o succesiune de
// cuvinte delimitate de "#".
// Sa se afiseze pe ecran sirul de caractere dupa inversarea
// cuvintelor de lungime maxima.

void spargere(char s[], char cuvinte[100][100], int& n) {
	char* a;
	a = strtok(s, "#");
	while (a != NULL) {
		strcpy(cuvinte[n], a);
		n++;
		a = strtok(NULL, "#");
	}
}

int maxLenght(char cuvinte[100][100], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int k = strlen(cuvinte[i]);
		if (k > max) {
			max = k;
		}
	}
	return max;
}

void inversare(char s[]) {
	char invers[100] = "";
	for (int i = strlen(s) - 1, j = 0; i > -1; i--, j++) {
		invers[j] = s[i];
	}
	strcpy(s, invers);
}

void inversareCuvinte(char cuvinte[100][100], int n) {
	int max = maxLenght(cuvinte, n);
	for (int i = 0; i < n; i++) {
		if (strlen(cuvinte[i]) == max) {			
			inversare(cuvinte[i]);
		}
	}
}

void afisareProblema1(char cuvinte[100][100], int n) {
	cout << "#";
	for (int i = 0; i < n; i++) {
		cout << cuvinte[i] << "#";
	}
	cout << endl;
}

void rezolvareSub3Problema1() {
	char s[100] = "";
	cin.getline(s, 100);
	
	char cuvinte[100][100];
	int n = 0;
	spargere(s, cuvinte, n);
	inversareCuvinte(cuvinte, n);
	afisareProblema1(cuvinte, n);
}

// Problema 2
// Subprogramul numarare are 4 parametrii (n, m numere naturale,
// a, b vectori de n, respectiv m elemente). 
// Subprogramul numarare returneaza cate valori din a sunt strict
// mai mici decat toate valorile din b.

// <=> Fisier Citire <=>
// Prima linie : doua numere (n, m)
// A doua linie : n numere (valorile lui a)
// A treia linie : m numere (valorile lui b)

void citireProblema2(int a[], int b[], int& n, int& m) {
	ifstream f("input.txt");
	f >> n >> m;
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}
	f.close();
}

int minim(int x[], int n) {
	int min = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] < min) {
			min = x[i];
		}
	}
	return min;
}

int numarare(int a[], int b[], int n, int m) {
	int min = minim(b, m);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < min) {
			c++;
		}
	}
	return c;
}

void rezolvareSub3Problema2() {
	int a[100], b[100], n, m;
	citireProblema2(a, b, n, m);
	cout << numarare(a, b, n, m);
}

// Problema 3
// Sa se afiseze lungimea maxima a unei secvente
// de tip fazan din vectorul citit din fisier.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int primaCifra(int n) {
	while (n / 10 > 0) {
		n /= 10;
	}
	return n;
}

int ultimaCifra(int n) {
	return n % 10;
}

bool fazan(int n, int m) {
	if (ultimaCifra(n) == primaCifra(m)) {
		return 1;
	}
	return 0;
}

int lenghtSecventaMaxFazan(int x[], int n) {
	int max = 0, l = 1;
	for (int i = 0; i < n; i++) {
		if (fazan(x[i], x[i + 1])) {
			l++;
			if (l > max) {
				max = l;
			}
		}
		else {
			l = 1;
		}
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	cout << lenghtSecventaMaxFazan(x, n);
}


