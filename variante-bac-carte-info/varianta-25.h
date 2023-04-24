#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(char s[]) {
	for (int i = 0; i < 5; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool apartine(char x, char consoane[]) {
	for (int i = 0; i < 3; i++) {
		if (x == consoane[i]) {
			return 1;
		}
	}
	return 0;
}

bool valid(int k, char s[]) {
	char consoane[3] = { 'B','C','D' };
	for (int i = 0; i < k; i++) {
		if (!apartine(s[i], consoane) && apartine(s[i + 1], consoane)) {
			return 0;
		}
		if (s[i] == s[k]) {
			return 0;
		}
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
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
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
	char x[5] = { 'A', 'B','C','D','E' };
	char s[5];

	back(x, s, 0);
}

// Subiectul 2

// Problema 3

// Se considera declararile :

struct triunghi {
	float l1, l2, l3;
};

void rezolvareSub2Problema3() {
	triunghi t[100];
	float x, y;
	int n, i;

	n = 3;
	t[0].l1 = 3, t[0].l2 = 4, t[0].l3 = 5;
	x = 2, y = 20;

	for (i = 0; i < n; i++) {
		float p = (t[i].l1 + t[i].l2 + t[i].l3) / 2;
		float arie = p * (p - t[i].l1) * (p - t[i].l2) * (p - t[i].l3);
		arie = sqrt(arie);
		if (arie >= x && arie <= y) {
			cout << t[i].l1 << " " << t[i].l2 << " " << t[i].l3 << " * ";
		}
	}
}

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int N;
	int x[10][19];

	cout << "Introduceti N : ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			x[i][j] = 2;
			if (j == i || j == 2 * N - 2 - i) {
				x[i][j] = 1;
			}
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

// Problema 2

void permutareStanga(int v[], int n) {
	int r = v[0];
	for (int i = 0; i < n - 1; i++) {
		v[i] = v[i + 1];
	}
	v[n - 1] = r;
}

int kpal(int v[100], int n, int k) {
	while (k != 0) {
		permutareStanga(v, n);
		k--;
	}

	for (int i = 0, j = n - 1; i < n; i++, j--) {
		if (v[i] != v[j]) {
			return 0;
		}
	}
	return 1;
}

void rezolvareSub3Problema2() {
	int n = 5;
	int v[5] = { 2,2,4,5,4 };
	cout << kpal(v, n, 2);
}

// Problema 3

bool cautare(int& L, int& C, int k, int& curent, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			curent++;
			if (curent == k) {
				L = i + 1;
				C = j + 1;
				return 1;
			}
		}
	}
	return 0;
}

void aflareTLC(int& T, int& L, int& C, int k) {
	int n = 2;
	int curent = 0;
	bool gasit = false;
	T = 0;
	while (!gasit) {
		gasit = cautare(L, C, k, curent, n);
		T++, n++;
	}
}

void rezolvareSub3Problema3() {
	int T, L, C, k;
	cout << "Introduceti k : ";
	cin >> k;
	aflareTLC(T, L, C, k);

	ofstream f("input.txt");
	f << T << " " << L << " " << C;
}