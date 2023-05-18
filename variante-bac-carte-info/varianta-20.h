#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				cout << 1;
			}
			else if (j == 3 - i) {
				cout << 7;
			}
			else {
				cout << j + 1;
			}
			cout << " ";
		}
		cout << endl;
	}
}

// Subiectul 3

// Problema 1

void separare(char s[], char numere[20][20], int& n) {
	n = 0;
	char* a;
	a = strtok(s, "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ");
	while (a != NULL) {
		strcpy(numere[n], a);
		n++;
		a = strtok(NULL, "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ");
	}
}

void rezolvareSub3Problema1() {
	char s[20] = "";
	cin.getline(s, 20);
	char numere[20][20];
	int n;
	separare(s, numere, n);

	int numar = 1;
	for (int i = 0; i < n; i++) {
		numar *= atoi(numere[i]);
	}
	cout << numar;
}

// Problema 2

int produs(int x[], int n) {
	int p = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] * x[j] > p) {
				p = x[i] * x[j];
			}
		}
	}
	return p;
}

void rezolvareSub3Problema2() {
	int x[6] = { -60,36,-8,-2,10,5 };
	cout << produs(x, 6);
}

// Problema 3

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void bubbleSortSentinel(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag&& i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j] > x[j - 1]) {
				int r = x[j];
				x[j] = x[j - 1];
				x[j - 1] = r;
				flag = true;
			}
		}
		i++;
	}
}

int primaCifra(int n) {
	while (n / 10 > 0) {
		n /= 10;
	}
	return n;
}

int countCifre(int n) {
	int c = 0;
	while (n > 0) {
		c++;
		n /= 10;
	}
	return c;
}

int numarInterior(int n) {
	n /= 10;
	return n % (int)(pow(10, countCifre(n) - 1));
}

void numereInterior(int x[], int n, int y[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 10 == primaCifra(x[i])) {
			y[m] = numarInterior(x[i]);
			m++;
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	int y[100], m;
	numereInterior(x, n, y, m);
	bubbleSortSentinel(y, m);
	for (int i = 0; i < m; i++) {
		cout << y[i] << " ";
	}
}