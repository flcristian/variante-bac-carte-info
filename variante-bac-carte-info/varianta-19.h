#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	char x[100][100];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i % 2 == 0) {
				x[i][j] = 'a';
			}
			else {
				x[i][j] = 'A';
			}
			if (j > 1) {
				x[i][j] = x[i][0] + 1;
			}
			cout << x[i][j] << " ";
		}
		cout << endl;
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

void removeVocaleSir1(char s1[], char litere[], int& n) {
	n = 0;
	for (int i = 0; i < strlen(s1); i++) {
		if (esteVocala(s1[i])) {
			litere[n] = s1[i];
			n++;

			char t[100] = "";
			strncpy(t, s1, i);
			strcat(t, s1 + i + 1);
			strcpy(s1, t);
		}
	}
}

void adaugareVocaleSir2(char s2[], char litere[], int n) {
	int i = 0, j = 0;
	while (n > 0) {
		char t[100] = "", r[3] = "";
		r[0] = litere[j];

		strncpy(t, s2, i);
		strcat(t, r);
		strcat(t, s2 + i);
		strcpy(s2, t);

		i += 2;
		j++;
		n--;
	}
}

void modificare(char s1[], char s2[]) {
	char litere[100];
	int n;
	removeVocaleSir1(s1, litere, n);
	adaugareVocaleSir2(s2, litere, n);
}

void rezolvareSub3Problema1() {
	char s1[40] = "", s2[40] = "";
	cin.getline(s1, 40);
	cin.getline(s2, 40);
	modificare(s1, s2);
	cout << s1 << " " << s2;
}

// Problema 2

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

int countDiv(int n) {
	int c = 0;
	for (int i = 1; pow(i, 2) <= n; i++) {
		if (n % i == 0) {
			c++;

			if (pow(i, 2) != n) {
				c++;
			}
		}
	}
	return c;
}

bool estePrim(int n) {
	if (countDiv(n) == 2) {
		return 1;
	}
	return 0;
}

void descompunereInFactori(int n, int f[]) {
	int i = 2;
	while (i <= n) {
		if (n % i == 0 && estePrim(i)) {
			f[i]++;
			n /= i;
		}
		else {
			i++;
		}
	}
}

void factor(int n, int x[], int& fp, int& p) {
	int r = cmmdc(x[0], x[1]);
	for (int i = 2; i < n; i++) {
		r = cmmdc(r, x[i]);
	}

	if (r == 1) {
		fp = -1, p = 0;
	}
	else {
		int f[100]{};
		descompunereInFactori(r, f);

		int k;
		for (int i = 0; i < 100; i++) {
			if (f[i] > 0) {
				k = i;
				break;
			}
		}
		fp = k, p = f[k];
	}
}

void rezolvareSub3Problema2() {
	int x[4] = { 60,36,18,24 };
	int y[4] = { 22,60,21,25 };
	int fp, p;
	factor(4, x, fp, p);
	cout << fp << " " << p;
}

// Problema 3

void tipar(int s[]) {
	for (int i = 0; i < 3; i++) {
		cout << s[i];
	}
	for (int i = 2; i > -1; i--) {
		cout << s[i];
	}
	cout << endl;
}

bool solutie(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

void back(int s[], int k) {
	for (int i = 1; i < 10; i += 2) {
		s[k] = i;
		if (solutie(k)) {
			tipar(s);
		}
		else {
			back(s, k + 1);
		}
	}
}

void rezolvareSub3Problema3() {
	int s[100];
	back(s, 0);
}