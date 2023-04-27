#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i % 2 == 1) { 
				cout << j + (i - 1) * 5;
			}
			else {
				cout << i * 5 + 1 - j;
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
// Se citesc de la tastatura doua doua siruri de caractere
// S si C. Sa se inlocuiasca fiecare litera S[i] din sir cu
// litera din alfabet aflata la distanta C[i].
// Daca sirul se termina, se reia de la litera a.

void modificare(char s[], char c[]) {
	for (int i = 0; i < strlen(s); i++) {
		char r[3] = "";
		r[0] = c[i];
		int n = atoi(r);
		s[i] = 97 + (s[i] + n) % 97;
	}
}

void rezolvareSub3Problema1() {
	char s[100], c[100];
	cin.getline(s, 100);
	cin.getline(c, 100);

	modificare(s, c);
	cout << s << endl;
}

// Problema 2
// Subprogramul permuta are trei parametri :
// n - numarul de elemente al vectorului a
// a - un vector
// k - un numar natural (1 <= k < n)
// Subprogramul permuta circular spre stanga cu k pozitii vectorul.

void citireProblema2(int a[], int& n, int& k) {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti a[" << i << "] : ";
		cin >> a[i];
	}
	cout << "Introduceti k : ";
	cin >> k;
}

void permutare(int a[], int n) {
	int r = a[0];
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	a[n - 1] = r;
}

void permuta(int a[], int n, int k) {
	while (k > 0) {
		permutare(a, n);
		k--;
	}
}

void afisareVector(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema2() {
	int a[100], n, k;
	citireProblema2(a, n, k);
	permuta(a, n, k);
	afisareVector(a, n);
}

// Problema 3
// Se citeste un sir de numere naturale dintr-un fisier.
// (S - sirul, n - numarul de elemente)
// Sa se sorteze sirul crescator.

void citireProblema3(int S[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> S[n];
		n++;
	}
	f.close();
}

void frecventaPuteri(int S[], int f[], int n) {
	for (int i = 0; i < n; i++) {
		int k = log10(S[i]);
		f[k]++;
	}
}

void sortareFrecventaPuteri(int S[], int f[], int n) {
	n = 0;
	for (int i = 0; i < 10; i++) {
		while (f[i] > 0) {
			S[n] = pow(10, i);
			n++;
			f[i]--;
		}
	}
}

void rezolvareSub3Problema3() {
	int S[100], n;
	citireProblema3(S, n);

	int f[10]{};
	frecventaPuteri(S, f, n);

	sortareFrecventaPuteri(S, f, n);
	afisareVector(S, n);
}