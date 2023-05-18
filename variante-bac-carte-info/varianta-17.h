#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	char x[100][100];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			x[i][j] = 'A' + (5 - i + j) % 5;
			cout << x[i][j];

			cout << " ";
			if (j == 4) {
				cout << endl;
			}
		}
	}
}

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

void separare(char s[], char cuvinte[250][250], int& m) {
	m = 0;
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[m], a);
		m++;
		a = strtok(NULL, " ");
	}
}

void modificare(char s[], char cuvinte[250][250], int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < strlen(cuvinte[i]) - 1; j++) {
			if (esteVocala(cuvinte[i][j]) != esteVocala(cuvinte[i][j + 1])) {
				int r = cuvinte[i][j];
				cuvinte[i][j] = cuvinte[i][j + 1];
				cuvinte[i][j + 1] = r;
			}
		}
		strcat(cuvinte[i], " ");
	}

	strcpy(s, "");
	for (int i = 0; i < m; i++) {
		strcat(s, cuvinte[i]);
	}
}

void rezolvareSub3Problema1() {
	char s[250] = "";
	cin.getline(s, 250);
	char cuvinte[250][250];
	int m;
	separare(s, cuvinte, m);
	modificare(s, cuvinte, m);
	cout << s;
}

// Problema 2

int termen(int n) {
	int x[100];
	x[0] = 1;
	int k = 3, p = 1, up = 0;
	while (p < n) {
		if (x[p - 1] == 1) {
			up = (up + 1) % 2;
		}
		else if (x[p - 1] == k) {
			up = (up + 1) % 2;
			k += 3;
		}
		if (up == 1) {
			x[p] = x[p - 1] + 1;
		}
		else {
			x[p] = x[p - 1] - 1;
		}
		p++;
	}
	return x[p - 1];
}

void rezolvareSub3Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << termen(n);
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

void secventa(int x[], int n, int& lenght, int& start) {
	lenght = 0, start = 0;
	for (int i = 0; i < n; i++) {
		int c1 = x[i] % 10;
		for (int j = n - 1; j > i; j--) {
			int c2 = x[j] % 10;
			if (c1 == c2) {
				int clenght = j - i + 1;
				if (clenght > lenght) {
					lenght = clenght;
					start = i + 1;
				}
				else if (clenght == lenght) {
					start = i + 1;
				}
				break;
			}			
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	int lenght, start;
	secventa(x, n, lenght, start);
	cout << lenght << " " << start;
}