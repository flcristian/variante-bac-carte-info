#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 3

// Problema 1
// Se citeste de la tastatura un numar n
// si un tablou bidimensional de n linii si n coloane
// cu elemente numere binare.
// Sa se inlocuiasca liniile formate doar din 0 cu
// numarul de 1 de pe coloana corespunzatoare.

void copiereVector(int x[], int y[], int n) {
	for (int i = 0; i < n; i++) {
		x[i] = y[i];
	}
}

void count1Linie(int x[100][100], int y[100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] == 1) {
				y[j]++;
			}
		}
	}
}

void afisare(int x[100][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void inlocuire(int x[100][100], int n) {
	int y[100]{};
	count1Linie(x, y, n);
	
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (x[i][j] == 0) {
				c++;
			}
		}
		if (c == n) {
			copiereVector(x[i], y, n);
		}
	}
}

void rezolvareSub3Problema1() {
	int x[100][100], n;
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}
	cout << endl;

	inlocuire(x, n);
	afisare(x, n);
}

// Problema 2 
// Scrieti un subprogram nPrime care are 3 parametrii
// n un numar natural, k prin care furnizeaza numerele
// prime cu n, mai mici decat n si vectorul p, in care
// vor fi puse aceste numere.

bool primeIntreEle(int n, int m) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0 && m % i == 0) {
			c++;
		}
	}

	if (c == 1) {
		return 1;
	}
	return 0;
}

void nPrime(int n, int& k, int p[]) {
	k = 0;
	for (int i = 1; i < n; i++) {
		if (primeIntreEle(i, n)) {
			p[k] = i;
			k++;
		}
	}
}

void afisareVector(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void rezolvareSub3Problema2() {
	int p[100], k, n = 20;
	nPrime(n, k, p);
	afisareVector(p, k);
}

// Problema 3
// ? ? ?

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void rezolvareSub3Problema3() {

}