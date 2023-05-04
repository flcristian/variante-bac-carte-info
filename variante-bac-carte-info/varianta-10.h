#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 3; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(string s[], int k) {
	bool flag1 = false, flag2 = false;
	for (int i = 0; i <= k; i++) {
		if (s[i] == s[k] && i != k) {
			return 0;
		}
		if (s[i] == "tableta" || s[i] == "joc") {
			if (flag1 == true) {
				return 0;
			}
			flag1 = true;
		}
		if (s[i] == "carte" || s[i] == "stilou") {
			if (flag2 == true) {
				return 0;
			}
			flag2 = true;
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

void back(string x[], string s[], int k) {
	for (int i = 0; i < 6; i++) {
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
	string x[6] = { "carte","tableta","joc","stilou","ceas","patine" };
	string s[100];
	back(x, s, 0);
}

// Subiectul 3

// Problema 1
// Sa se scrie un subprogram divprim care primeste
// ca parametrii n, k si un vector de k elemente si
// cauta cel mai mic divizor prim al numarului n.
// Acest divizor il cauta in vectorul v, iar daca nu este
// gasit, este adaugat pe pozitia corespunzatoare incat
// vectorul sa fie crescator.

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

bool estePrim(int n) {
	if (countDiv(n) == 2) {
		return 1;
	}
	return 0;
}

int cmmdp(int n) {
	for (int i = 2; i <= n; i++) {
		if (n % i == 0 && estePrim(i)) {
			return i;
		}
	}
	return -1;
}

void inserare(int x[], int& n, int k, int nr) {
	for (int i = n; i > k; i--) {
		x[i] = x[i - 1];
	}
	x[k] = nr;
	n++;
}

void divprim(int n, int& k, int v[]) {
	int d = cmmdp(n);
	bool flag = false;
	int i = 0;
	while (!flag && i < k) {
		if (d == v[i]) {
			cout << i + 1;
			flag = true;
		}
		else if (d < v[i]) {
			inserare(v, k, i, d);
			flag = true;
		}
		else {
			i++;
		}
	}
	if (!flag) {
		inserare(v, k, k, d);
	}
}

void afisare(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema1() {
	int x[100] = { 2,5,11,17 };
	int k = 4, n = 27;
	divprim(n, k, x);
	afisare(x, k);
}

// Problema 2
// Sa se inlocuiasca cuvintele duble
// dintr-o propozitie citita de la tastatura
// cu "*"
// (ex : tictic = cuvant dublu)

void separare(char cuvinte[255][255], char s[], int& n) {
	n = 0;
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[n], a);
		n++;
		a = strtok(NULL, " ");
	}
}

void inlocuire(char cuvinte[255][255], int n) {
	char r[3] = "*";
	for (int i = 0; i < n; i++) {
		char s1[255] = "", s2[255] = "";
		strncpy(s1, cuvinte[i], strlen(cuvinte[i]) / 2);
		strcpy(s2, cuvinte[i] + strlen(cuvinte[i]) / 2);
		if (strcmp(s1, s2) == 0) {
			strcpy(s2, r);
			strcat(s1, s2);
			strcpy(cuvinte[i], s1);
		}
	}
}

void afisareCuvinte(char cuvinte[255][255], int n) {
	for (int i = 0; i < n; i++) {
		cout << cuvinte[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema2() {
	char s[255] = "";
	cin.getline(s, 255);
	char cuvinte[255][255];
	int n;
	separare(cuvinte, s, n);
	inlocuire(cuvinte, n);
	afisareCuvinte(cuvinte, n);
}

// Problema 3
// Sa se afiseze numarul k pentru care intervalul
// [2^k, 2^k+1) contine cele mai multe numere din
// vectorul citit din fisier.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void frecventa(int x[], int f[], int n) {
	for (int i = 0; i < n; i++) {
		f[(int)log2(x[i])]++;
	}
}

int maxFreq(int f[]) {
	int max = 0, r = 39;
	for (int i = 39; i > -1; i--) {
		if (f[i] > max) {
			max = f[i];
			r = i;
		}
	}
	return r;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	int f[40]{};
	frecventa(x, f, n);
	cout << maxFreq(f);
}