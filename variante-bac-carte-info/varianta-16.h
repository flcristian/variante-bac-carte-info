#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 3

// Problema 1

bool exista(char x[20][20], int n) {
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (x[i][j] == 'U') {
				flag = false;
			}
		}
		if (flag) {
			return 1;
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (x[j][i] == 'U') {
				flag = false;
			}
		}
		if (flag) {
			return 1;
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag1 = true, flag2 = true;
		for (int j = 0; j < n; j++) {
			if (i == j && x[i][j] == 'U') {
				flag1 = false;
			}
			if (j == n - i - 1 && x[i][j] == 'U') {
				flag2 = false;
			}
		}
		if (flag1 || flag2) {
			return 1;
		}
	}

	return 0;
}

void citire(char x[20][20], int& n) {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Introduceti x[" << i << "][" << j << "] : ";
			cin >> x[i][j];
		}
	}
}

void rezolvareSub3Problema1() {
	char x[20][20];
	int n;
	citire(x, n);
	if (exista(x, n)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}
}

// Problema 2

void despartire(int x[], int n, int& m) {
	m = 0;
	while (n > 0) {
		x[m] = n % 10;
		m++;
		n /= 10;
	}
}

void inserarePos(int x[], int& n, int k, int c) {
	for (int i = n; i > k; i--) {
		x[i] = x[i - 1];
	}
	x[k] = c;
	n++;
}

void adaugare(int x[], int& m, int c) {
	for (int i = m - 1; i > -1; i--) {
		if (x[i] < c) {
			inserarePos(x, m, i + 1, c);
			return;
		}
	}
}

int nMax(int n, int c) {
	int x[100], m;
	despartire(x, n, m);
	adaugare(x, m, c);
	int nou = 0;
	for (int i = m - 1; i > -1; i--) {
		nou = nou * 10 + x[i];
	}
	return nou;
}

void rezolvareSub3Problema2() {
	int n, c;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti c : ";
	cin >> c;
	cout << nMax(n, c);
}

// Problema 3

// ? ? ? ?

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
}