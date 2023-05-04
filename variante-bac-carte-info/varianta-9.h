#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(char s[], int k) {
	for (int i = 0; i <= k; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(char s[], int k) {
	int ca = 0, cb = 0;
	for (int i = 0; i <= k; i++) {
		if (s[i] == 'A') {
			ca++;
		}
		if (s[i] == 'B') {
			cb++;
		}
	}
	if (ca > 3 || cb > 3) {
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

void back(char x[], char s[], int k) {
	for (int i = 0; i < 2; i++) {
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
	char x[2] = { 'A','B' };
	char s[10];
	back(x, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	for (int i = 0; i <= 5; i++) {
		for (int j = 5; j >= 0; j--) {
			if (5 - i == j) {
				cout << 6;
			}
			else if (i % 2 == 0) {
				cout << 5 - i;
			}
			else {
				cout << j;
			}
			cout << " ";

			if (j == 0) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1
// Sa se scrie un subprogram, denumit circular, care
// returneaza cate permutari circulare spre dreapta
// ale cifrei lui A sunt necesare ca numarul sa fie 
// egal cu B.

int countCifre(int n) {
	int c = 0;
	while (n > 0) {
		c++;
		n /= 10;
	}
	return c;
}

int permutare(int n) {
	int r = n % 10;
	int p2 = n / 10;
	return r * pow(10, countCifre(n) - 1) + p2;
}

int circular(int a, int b) {
	int n = countCifre(b);
	for (int i = 0; i < n + 1; i++) {
		cout << a << " " << b << endl;
		if (a == b) {
			return i;
		}
		a = permutare(a);
	}
	return -1;
}

void rezolvareSub3Problema1() {
	int a, b;
	cout << "Introduceti a : ";
	cin >> a;
	cout << "Introduceti b : ";
	cin >> b;

	cout << circular(a, b);
}

// Problema 2
// Se citeste o propozitie si un cuvant a.
// Sa se afiseze cuvintele din propozitie care rimeaza
// cu cuvantul a.

void separare(char cuvinte[255][255], char s[], int& n) {
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[n], a);
		n++;
		a = strtok(NULL, " ");
	}
}

bool esteVocala(char a) {
	char x[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < 5; i++) {
		if (a == x[i]) {
			return 1;
		}
	}
	return 0;
}

int sufix(char cuvant[]) {
	for (int i = strlen(cuvant) - 1; i > -1; i++) {
		if (esteVocala(cuvant[i])) {
			return i;
		}
	}
	return 0;
}

void careRimeaza(char cuvinte[255][255], char rimeaza[255][255], char cuv[255], int n, int& m) {
	char suf1[255] = "";
	strcpy(suf1, cuv + sufix(cuv));
	for (int i = 0; i < n; i++) {
		char suf2[255] = "";
		cout << suf2 << endl;
		strcpy(suf2, cuvinte[i] + sufix(cuvinte[i]));
		if (strcmp(suf1, suf2) == 0) {
			strcpy(rimeaza[m], cuvinte[i]);
			m++;
		}
	}
}

void afisareCuvinte(char x[255][255], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << endl;
	}
}

void rezolvareSub3Problema2() {
	char s[255] = "", cuv[255] = "";
	cout << "Introduceti propozitia :" << endl;
	cin.getline(s, 255);
	cout << "Introduceti cuvantul :" << endl;
	cin.getline(cuv, 255);

	char cuvinte[255][255], rimeaza[255][255];
	int n = 0, m = 0;
	separare(cuvinte, s, n);
	careRimeaza(cuvinte, rimeaza, cuv, n, m);
	afisareCuvinte(rimeaza, m);
}

// ? ? ? ? ? ? ?

// Problema 3
// Se da un vector. Sa se afiseze se aseaza elementele incat sa se formeze
// un numar palindrom, sau sa se afiseze -1 daca nu se poate.

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
		f[x[i]]++;
	}
}

bool sePotRearanja(int f[]) {
	int c = 0;
	for (int i = 0; i < 10; i++) {
		if (f[i] % 2 == 1) {
			c++;
		}
		if (c == 2) {
			return 0;
		}
	}
	return 1;
}

int mid(int f[]) {
	for (int i = 0; i < 10; i++) {
		if (f[i] % 2 == 1) {
			return i;
		}
	}
	return -1;
}

void rearanjare(int x[], int f[], int n) {
	int i = 9, j = 0, m = mid(f);
	n = 0;

	while (i > -1) {
		if (j < f[i] / 2) {
			x[n] = i;
			n++;
			j++;
		} 
		else {
			i--;
			j = 0;
		}
	}
	if (m != -1) {
		x[n] = m;
		n++;
	}
	i = 0, j = 0;
	while (i < 10) {
		if (j < f[i] / 2) {
			x[n] = i;
			n++;
			j++;
		}
		else {
			i++;
			j = 0;
		}
	}
}

void afisare(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	int f[10]{};
	frecventa(x, f, n);
	if (sePotRearanja(f)) {
		rearanjare(x, f, n);
		afisare(x, n);
	}
	else {
		cout << -1;
	}
}