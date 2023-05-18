#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 3

// Problema 1

bool esteVocala(char x) {
	char vocale[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < 5; i++) {
		if (x == vocale[i]) {
			return 1;
		}
	}
	return 0;
}

void separare(char s[], char cuvinte[500][500], int& m) {
	m = 0;
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[m], a);
		m++;
		a = strtok(NULL, " ");
	}
}

void removePos(char cuvinte[500][500], int& m, int k) {
	for (int i = k; i < m - 1; i++) {
		strcpy(cuvinte[i], cuvinte[i + 1]);
	}
	m--;
}

void modificare(char s[], char c[]) {
	char cuvinte[500][500];
	int m;
	separare(s, cuvinte, m);

	for (int i = 1; i < m; i++) {
		if (esteVocala(cuvinte[i - 1][0]) && strcmp(c, cuvinte[i]) == 0) {
			removePos(cuvinte, m, i);
			i--;
		}
	}

	strcpy(s, "");
	for (int i = 0; i < m; i++) {
		strcat(s, cuvinte[i]);
		strcat(s, " ");
	}
}

void rezolvareSub3Problema1() {
	char s[500] = "", c[10] = "";
	cin.getline(s, 500);
	cin.getline(c, 10);
	char old[500] = "";
	strcpy(old, s);

	modificare(s, c);

	if (strcmp(old, s) == 0) {
		cout << "Textul nu s-a modificat";
	}
	else {
		cout << s;
	}
}

// Problema 2

bool primeIntreEle(int a, int b) {
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	if (a == 1) {
		return 1;
	}
	return 0;
}

int prime(int x[], int n) {
	int c = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (primeIntreEle(x[i], x[j])) {
				c++;
			}
		}
	}
	return c;
}

void rezolvareSub3Problema2() {
	int x[6] = { 42,3,14,43,8,6 };
	cout << prime(x, 6);
}