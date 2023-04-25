#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
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
	for (int i = 0; i < 5; i++) {
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
	string x[5] = { "mosc","santal","tuberoze","liliac","lavanda" };
	string s[100];
	back(x, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j > i && j < 5 - i + 1) {
				cout << 1;
			}
			else if (j > i && j > 5 - i + 1) {
				cout << 2;
			}
			else if (j > 5 - i + 1 && i > j) {
				cout << 3;
			}
			else if (j < i && i < 5 - j + 1) {
				cout << 4;
			}
			else {
				cout << 0;
			}
			cout << " ";

			if (j == 5) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1
// Sa se tipareasca toate cuvintele
// care se pot obtine prin concatenarea
// prefixelor si sufixelor unui cuvant
// citit de la tastatura.

void cuvintePrinConcatenare(char s[]) {
	int n = strlen(s);
	for (int i = 1; i < n + 1; i++) {
		if (i == n / 2) {
			i++;
		}
		char t[100] = "";
		strncpy(t, s, i);
		strcat(t, s + n - i);
		cout << t << " ";
	}
}

void rezolvareSub3Problema1() {
	char s[100] = "";
	cin.getline(s, 100);

	cuvintePrinConcatenare(s);
}

// Problema 2
// Subprogramul divizori are un paramentru n
// numar natural si returneaza suma divizorilor
// primi ai lui n.

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

int divizori(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0 && estePrim(i)) {
			s += i;
		}
	}
	return s;
}

void rezolvareSub3Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << divizori(n);
}

// Problema 3
// Sa se afiseze de cate ori se prelucreaza
// un vector pana nu mai contine niciun numar.
// (prelucrare = se sterg valorile prime si se
// adauga 1 la cele neprime)
// Vectorul este citit din fisier si contine
// numere naturale de maxim 3 cifre.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void eliminarePozitie(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void prelucrare(int x[], int& n) {
	for (int i = 0; i < n; i++) {
		if (estePrim(x[i])) {
			eliminarePozitie(x, n, i);
			i--;
		}
		else {
			x[i]++;
		}
	}
}

void prelucrari(int x[], int& n, int& c) {
	c = 0;
	while (n > 0) {
		prelucrare(x, n);
		c++;
	}
}

void rezolvareSub3Problema3() {
	int x[100], n, c;
	citireProblema3(x, n);
	prelucrari(x, n, c);
	cout << c << endl;
}


