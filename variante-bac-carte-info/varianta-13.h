#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 3

// Problema 1

void separare(char s[], char cuvinte[200][200], int& n) {
	n = 0;
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[n], a);
		n++;
		a = strtok(NULL, " ");
	}
}

bool contineCifra(char c[]) {
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] > 47 && c[i] < 58) {
			return 1;
		}
	}
	return 0;
}

void tiparire(char cuvinte[200][200], int n) {
	for (int i = 0; i < n; i++) {
		if (!contineCifra(cuvinte[i])) {
			cout << cuvinte[i][0];
		}
	}
}

void rezolvareSub3Problema1() {
	char s[200] = "";
	cin.getline(s, 200);
	char cuvinte[200][200];
	int n;
	separare(s, cuvinte, n);
	tiparire(cuvinte, n);
}

// Problema 3

void citireProblema3(int x[], int& n, int& k) {
	ifstream f("input.txt");
	f >> k;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

bool esteSufix(int n, int suf) {
	int k = 10;
	while (n / k > 0) {
		if (n % k == suf) {
			return 1;
		}
		k *= 10;
	}
	return 0;
}

void numarSufix(int x[], int n, int k, int& last) {
	for (int i = 0; i < n; i++) {
		if (esteSufix(x[i], k)) {
			last = x[i];
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n, k;
	citireProblema3(x, n, k);
	int last;
	numarSufix(x, n, k, last);
	cout << last;
}