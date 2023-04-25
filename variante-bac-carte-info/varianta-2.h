#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(int s[], int k) {
	for (int i = 0; i < k + 1; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int s[], int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

void back(int x[], int s[], int n, int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(s, k)) {
			if (solutie(k)) {
				tipar(s, k);
			}
			else {
				back(x, s, n, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int x[4] = { 5,6,7,8 };
	int s[100];
	back(x, s, 4, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i + j < 6) {
				cout << 1;
			}
			else if (i + j == 6) {
				cout << 3;
			}
			else {
				cout << 2;
			}
			cout << " ";

			if (j == 5) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1
// Sa se afiseze litera sau literele care apar
// de cele mai multe ori in sir.

void frecventaLitere(char s[], int f[]) {
	for (int i = 0; i < strlen(s); i++) {
		f[s[i] - 97]++;
	}
}

void litereMaxAparitie(char litere[], int f[], int& n, int& max) {
	n = 0, max = 0;
	for (int i = 0; i < 26; i++) {
		if (f[i] > max) {
			max = f[i];
			n = 0;
		}
		if (f[i] == max) {
			litere[n] = 97 + i;
			n++;
		}
	}
}

void afisareLitere(char litere[], int n, int max) {
	for (int i = 0; i < n; i++) {
		cout << litere[i] << " ";
	}
	cout << max << endl;
}

void rezolvareSub3Problema1() {
	char s[100] = "";
	cin.getline(s, 100);
	_strlwr(s);
	int f[26]{};
	frecventaLitere(s, f);

	char litere[100];
	int n, max;
	litereMaxAparitie(litere, f, n, max);
	afisareLitere(litere, n, max);
}

// Problema 2
// Subprogramul numarare primeste doi parametrii :
// a si b, numere naturale.
// Subprogramul returneaza cate numere din intervalul
// inchis determinat de a si b au exact 3 divizori.

int countDiv(int n) {
	int c = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			c++;
			if (pow(i, 2) != n) {
				c++;
			}
		}
	}
	return c;
}

int numarare(int a, int b) {
	if (a > b) {
		int r = a;
		a = b;
		b = r;
	}

	int count = 0;
	for (int i = a; i <= b; i++) {
		if (countDiv(i) == 3) {
			count++;
		}
	}
	return count;
}

void rezolvareSub3Problema2() {
	int a, b;
	cout << "Introduceti a : ";
	cin >> a;
	cout << "Introduceti b : ";
	cin >> b;
	
	cout << numarare(a, b) << endl;
}

// Problema 3
// Se citesc doua numere naturale si doi vectori
// de lungimi corespunzatoare celor doua numere.
// Sa se determine de cate ori poate fi format
// vectorul b utilizand valorile din vectorul a,
// daca li se pot schimba pozitiile.
// Elementele vectorilor sunt cifre. 

// <=> Fisier Citire <=>
// Prima linie : doua numere (n, m)
// A doua linie : n numere (valorile lui a)
// A treia linie : m numere (valorile lui b)

void citireProblema3(int a[], int b[], int& n, int& m) {
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

void frecventaVector(int x[], int f[], int n) {
	for (int i = 0; i < n; i++) {
		f[x[i]]++;
	}
}

int numarVectori(int fa[], int fb[]) {
	for (int i = 0; i < 10; i++) {
		if (fb[i] == 0) {
			fa[i] = 0;
		}
	}

	int min = 9999999;
	for (int i = 0; i < 10; i++) {
		if (fb[i] > 0 && fa[i] > 0) {
			int k = fa[i] / fb[i];
			if (k < min) {
				min = k;
			}
		}
	}
	return min;
}

void rezolvareSub3Problema3() {
	int a[100], b[100], n, m;
	citireProblema3(a, b, n, m);

	int fa[10]{}, fb[10]{};
	frecventaVector(a, fa, n);
	frecventaVector(b, fb, m);

	cout << numarVectori(fa, fb) << endl;
}
