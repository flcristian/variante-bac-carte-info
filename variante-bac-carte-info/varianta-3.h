#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(int s[], int k) {
	for (int i = 0; i < k + 1; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int s[], int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k, int m) {
	if (k == m) {
		return 1;
	}
	return 0;
}

void back(int x[], int s[], int n, int m, int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(s, k)) {
			if (solutie(k, m)) {
				tipar(s, k);
			}
			else {
				back(x, s, n, m, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int x[5] = { 1,2,3,4,5 };
	int s[100];
	for (int i = 0; i < 5; i++) {
		back(x, s, 5, i, 0);
	}
}

// Subiectul 3

// Problema 1
// Se citeste din fisier un numar natural impar
// si un tablou de n linii si n coloane.
// Sa se stearga linia si coloana mijlocie
// si sa se afiseze pe ecran vectorulrezultat.

void citireProblema1(int x[100][100], int& n) {
	ifstream f("input.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> x[i][j];
		}
	}
	f.close();
}

void stergereLinieColoana(int x[100][100], int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = n / 2; j < n - 1; j++) {
			x[i][j] = x[i][j + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n / 2; j < n - 1; j++) {
			x[j][i] = x[j + 1][i];
		}
	}
	n--;
}

void afisareProblema1(int x[100][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void rezolvareSub3Problema1() {
	int x[100][100], n;
	citireProblema1(x, n);
	stergereLinieColoana(x, n);
	afisareProblema1(x, n);
}

// Problema 2
// Subprogramul numar primeste doi parametrii :
// n un numar natural, m prin care furnizeaza cel mai
// mare numar care se poate forma utilizand doar
// cifrele impare ale lui n.

void frecventaCifreImpare(int n, int f[]) {
	while (n > 0) {
		int c = n % 10;
		if (c % 2 == 1) {
			f[c / 2]++;
		}
		n /= 10;
	}
}

void numar(int n, int& m) {
	int f[5]{};
	frecventaCifreImpare(n, f);
	m = 0;
	int i = 4;
	while (i > -1) {
		if (f[i] > 0) {
			m = m * 10 + i * 2 + 1;
			f[i]--;
		}
		else {
			i--;
		}
	}

	if (m == 0) {
		m = -1;
	}
}

void rezolvareSub3Problema2() {
	int n, m;
	cout << "Introduceti n : ";
	cin >> n;
	numar(n, m);
	cout << m << endl;
}

// Problema 3
// Se citesc de la tastatura trei numere, n, m si k.
// Subprogramul afiseaza numerele de k cifre care sunt
// divizibile cu n si m.

void numere(int n, int m, int k) {
	for (int i = pow(10, k - 1); i < pow(10, k); i++) {
		if (i % n == 0 && i % m == 0) {
			cout << i << " ";
		}
	}
	cout << endl;
}

void rezolvareSub3Problema3() {
	int n, m, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	cout << "Introduceti k : ";
	cin >> k;

	numere(n, m, k);
}


