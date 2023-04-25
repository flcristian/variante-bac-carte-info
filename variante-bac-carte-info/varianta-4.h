#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(char s[], int k) {
	for (int i = 0; i < k + 1; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(char s[], int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[i + 1]) {
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

void back(char x[], char s[], int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(s, k)) {
			if (solutie(k)) {
				tipar(s, k);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	char x[5] = { 'a','b','c','d','e' };
	char s[100];
	back(x, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	int x[100][100];
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i == 1 || j == 1) {
				x[i][j] = 1;
				cout << 1 << " ";
			}
			else {
				x[i][j] = (x[i - 1][j] + x[i][j - 1]) % 10;
				cout << x[i][j] << " ";
			}
			if (j == 5) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1
// Sa se insereze caracterul "#" intre oricare doua caractere
// alaturate identice.

void inserarePozitieCaracter(char s[], int k) {
	char t[100] = "";
	strncpy(t, s, k);
	t[strlen(t)] = '#';
	strcat(t, s + k);
	strcpy(s, t);
}

void separarePrinCaracter(char s[]) {
	for (int i = 0; i < strlen(s) - 1; i++) {
		if (s[i] == s[i + 1]) {
			inserarePozitieCaracter(s, i + 1);
			i++;
		}
	}
}

void rezolvareSub3Problema1() {
	char s[100] = "";
	cin.getline(s, 100);
	separarePrinCaracter(s);
	cout << s << endl;
}

// Problema 2
// Subprogramul numarare are doi parametri :
// n si m, numere naturale, n <= m
// Subprogramul returneaza numarul de cifre necesar
// pentru construirea numerelor naturale din
// intervalul [n, m].

int countCifre(int n) {
	int c = 0;
	while (n > 0) {
		c++;
		n /= 10;
	}
	return c;
}

int numarare(int n, int m) {
	int c = 0;
	for (int i = n; i <= m; i++) {
		c += countCifre(i);
	}
	return c;
}

void rezolvareSub3Problema2() {
	int n, m;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	
	cout << numarare(n, m);
}

// Problema 3
// Sa se afiseze pe ecran numerele cu numarul
// de aparitii maxim din vectorul citit din fisier.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void frecventaNumere(int x[], int f[], int n) {
	for (int i = 0; i < n; i++) {
		f[x[i] + 100]++;
	}
}

void numereFrecventaMax(int f[], int numere[], int& m) {
	int max = 0;
	m = 0;
	for (int i = 0; i < 200; i++) {
		if (f[i] > max) {
			max = f[i];
			m = 0;
		}
		if (f[i] == max) {
			numere[m] = i - 100;
			m++;
		}
	}
}

void afisareNumere(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	
	int f[200]{};
	frecventaNumere(x, f, n);
	
	int numere[100], m;
	numereFrecventaMax(f, numere, m);
	afisareNumere(numere, m);
}