#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 1

// Problema 3

void tipar(int s[]) {
	for (int i = 0; i < 4; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int s[], int k) {
	for (int i = 0; i <= k; i++) {
		if (s[i] <= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int s[], int k) {
	if (k == 3) {
		int suma = 0;
		for (int i = 0; i <= k; i++) {
			suma += s[i];
		}
		if (suma % 2 == 0) {
			return 1;
		}
	}
	return 0;
}

void back(int s[], int k) {
	for (int i = 1; i < 10 && k < 4; i++) {
		s[k] = i;
		if (solutie(s, k)) {
			if (valid(s, k)) {
				tipar(s);
			}
		}
		else {
			back(s, k + 1);
		}
	}
}

void rezolvareSub1Problema3() {
	int s[100];
	back(s, 0);
}

// Subiectul 3

// Problema 2

void termen(int n, int& m, int& t) {
	int x[100];
	x[0] = 0, x[1] = 1;
	int k = 2;
	while (n >= x[k - 1]) {
		x[k] = x[k - 1] + x[k - 2];
		k++;
	}
	if (x[k - 2] == n) {
		m = x[k - 3];
	}
	else {
		m = x[k - 2];
	}
	t = x[k - 1];
}

void rezolvareSub3Problema2() {
	int n, m, t;
	cout << "Introduceti n : ";
	cin >> n;
	termen(n, m, t);
	cout << m << " " << t;
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

void formareVarfuri(int x[], int n, int v[], int& m) {
	m = 0;
	int s = 0;
	if (x[1] > x[0]) {
		s = 1;
	}

	for (int i = 2; i < n; i++) {
		if (x[i] > x[i - 1] && s != 1 || x[i] < x[i - 1] && s != 0) {
			if (x[i] < x[i - 1] && s == 1) {
				v[m] = x[i - 1];
				m++;
			}
			s = (s + 1) % 2;
		}
	}
}

void bubbleSortSentinel(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag&& i < n) {
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
	int x[100], n;
	citireProblema3(x, n);
	int v[100], m;
	formareVarfuri(x, n, v, m);
	bubbleSortSentinel(v, m);
	for (int i = 0; i < m; i++) {
		cout << v[i] << " ";
	}
}