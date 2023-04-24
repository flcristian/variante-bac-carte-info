#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Subiectul 2

// Problema 2

void rezolvareSub2Problema2() {
	int i, j, A[5][5];
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (j == 4) {
				cout << -2;
				A[i][j] = -2;

			}
			else if (i == 0) {
				cout << j + 1;
				A[i][j] = j + 1;
			}
			else {
				cout << A[i - 1][j] + A[i - 1][j + 1];
				A[i][j] = A[i - 1][j] + A[i - 1][j + 1];
			}
			cout << " ";
		}
		cout << endl;
	}
}

// Subiectul 3

// Problema 2

bool cifrePare(int x) {
	while (x > 0) {
		if ((x % 10) % 2 == 1) {
			return 0;
		}
		x /= 10;
	}
	return 1;
}

int maxim(int n, int m, int T[30][30]) {
	for (int i = 0; i < n; i++) {
		if (T[i][0] % 2 == 1) {
			int maxim = 0;
			for (int j = 1; j < m; j++) {
				if (cifrePare(T[i][j]) && T[i][j] > maxim) {
					maxim = T[i][j];
				}
			}
			return maxim;
		}
	}
	return -1;
}

void rezolvareSub3Problema2() {
	int n, m, T[30][30];
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "Introduceti T[" << i << "][" << j << "] : ";
			cin >> T[i][j];
		}
	}

	cout << maxim(n, m, T);
}

// Problema 3

void citire(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int pcf(int x) {
	return x / 100;
}

void maxSecventa(int x[], int n, int& m, int& count) {
	m = 0;
	int curent = 1, cifra = pcf(x[0]);
	count = 1;
	for (int i = 1; i < n; i++) {
		if (pcf(x[i]) == cifra) {
			curent++;
			if (curent == m) {
				count++;
			}
			if (curent > m) {
				m = curent;
				count = 1;
			}
		}
		else {
			cifra = pcf(x[i]);
			curent = 1;
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100000], n;
	citire(x, n);
	int m, cate;
	maxSecventa(x, n, m, cate);
	cout << m << " " << cate << endl;
}