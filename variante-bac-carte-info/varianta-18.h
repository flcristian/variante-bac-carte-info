#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 5; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(string s[], int k) {
	bool contineCrin = 0, contineTrandafir = 0;
	for (int i = 0; i <= k; i++) {
		if (s[i] >= s[i + 1] && i < k) {
			return 0;
		}
		if (s[i] == "crin") {
			contineCrin = 1;
		}
		if (s[i] == "trandafir") {
			contineTrandafir = 1;
		}
	}
	if (contineCrin && contineTrandafir) {
		return 0;
	}
	return 1;
}

bool solutie(int k) {
	if (k == 4) {
		return 1;
	}
	return 0;
}

void back(string x[], string s[], int k) {
	for (int i = 0; i < 7; i++) {
		s[k] = x[i];
		if (valid(s, k)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[7] = { "lalea","narcisa","crin","crizantema","trandafir","garoafa","frezie" };
	string s[100];
	back(x, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int x[100][100];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 || j == 0) {
				x[i][j] = 2;
			}
			else {
				x[i][j] = x[i - 1][j] + x[i][j - 1];
			}
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

// Subiectul 3

// Problema 1

void separarePropozitii(char s[], char propozitii[200][200], int& n) {
	n = 0;
	char* a;
	a = strtok(s, ".");
	while (a != NULL) {
		strcpy(propozitii[n], a);
		n++;
		a = strtok(NULL, ".");
	}
}

void separare(char s[], char cuvinte[200][200], int& m) {
	char text[200] = "";
	strcpy(text, s);
	m = 0;
	char* b;
	b = strtok(text, " ");
	while (b != NULL) {
		strcpy(cuvinte[m], b);
		m++;
		b = strtok(NULL, " ");
	}
}

void propozitieMaxAparitiiCuv(char propozitii[200][200], char c[], int n) {
	int max = 0, maxProp = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		char cuvinte[200][200];
		int m;
		separare(propozitii[i], cuvinte, m);

		for (int j = 0; j < m; j++) {
			if (strcmp(cuvinte[j], c) == 0) {
				cout << i << endl;
				count++;
			}
		}
		if (count > max) {
			max = count;
			maxProp = i;
		}
	}

	cout << propozitii[maxProp];
}

void rezolvareSub3Problema1() {
	char c[20] = "", s[200] = "";
	cin.getline(c, 20);
	cin.getline(s, 200);
	char propozitii[200][200];
	int n;
	separarePropozitii(s, propozitii, n);
	propozitieMaxAparitiiCuv(propozitii, c, n);
}

// Problema 2

int oglindit(int n) {
	int o = 0;
	while (n > 0) {
		o = o * 10 + n % 10;
		n /= 10;
	}
	return o;
}

int perechi(int x[100], int n) {
	int c = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] == oglindit(x[j])) {
				c++;
				break;
			}
		}
	}
	return c;
}

void rezolvareSub3Problema2() {
	int x[7] = { 41,324,14,423,82,6,28 };
	cout << perechi(x, 7);
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

// ? ? ? ? ? ? ?

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
}