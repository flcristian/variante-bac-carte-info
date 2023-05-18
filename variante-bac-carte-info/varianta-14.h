#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (j == 0 || j == 6) {
				cout << "*";
			}
			else if ((j == i || j == 6 - i) && i < 4) {
				cout << "*";
			}
			else {
				cout << "-";
			}
			
			cout << " ";
			if (j == 6) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

void separare(char s[], char cuvinte[200][200], int& m) {
	m = 0;
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(cuvinte[m], a);
		m++;
		a = strtok(NULL, " ");
	}
}

bool estePosibil(char cuvinte[200][200], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (strlen(cuvinte[i]) > n) {
			return 0;
		}
	}
	return 1;
}

void wrap(char cuvinte[200][200], int n, int m) {
	if (estePosibil(cuvinte, m, n)) {
		int r = n;
		for (int i = 0; i < m; i++) {
			int lenght = strlen(cuvinte[i]);
			if (lenght <= r) {
				cout << cuvinte[i];
				r -= lenght;

				if (r > 1) {
					cout << " ";
					r--;
				}
			}
			else {
				i--;
				while (r > 0) {
					cout << "*";
					r--;
				}
				r = n;
				cout << endl;
			}
		}
	}
	else {
		cout << "IMPOSIBIL";
	}
}

void rezolvareSub3Problema1() {
	char s[200] = "", numar[10] = "";
	cin.getline(numar, 10);
	int n = atoi(numar);
	cin.getline(s, 200);
	char cuvinte[200][200];
	int m;
	separare(s, cuvinte, m);
	wrap(cuvinte, n, m);
}

// Problema 2

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

bool descompunereDoarIn235(int n) {
	int i = 2;
	while (n > 1) {
		if (estePrim(i) && n % i == 0) {
			if (i > 5) {
				return 0;
			}
			n /= i;
		}
		else {
			i++;
		}
	}
	return 1;
}

int regulat(int n) {
	for (int i = n; i > 1; i--) {
		if (descompunereDoarIn235(i)) {
			return i;
		}
	}
	return -1;
}

void rezolvareSub3Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	cout << regulat(n);
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

void bubbleSortSentinel(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j] < x[j - 1]) {
				int r = x[j];
				x[j] = x[j - 1];
				x[j - 1] = r;
				flag = true;
			}
		}
		i++;
	}
}

void rezolvareSub3Problema3() {
	int x[100], n, k;
	citireProblema3(x, n, k);
	if (k > n) {
		cout << -1;
	}
	else {
		bubbleSortSentinel(x, n);
		cout << x[k - 1];
	}
}