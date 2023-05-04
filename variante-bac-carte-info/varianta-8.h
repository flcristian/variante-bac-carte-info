#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int n, i;
	char s[100] = "";

	n = 0;
	for (int i = 1; i <= 5; i++) {
		cin.getline(s, 100);
		if (strstr(s, "2019") == s) {
			n++;
			if (strstr(s + 1, "2019") != NULL) {
				n--;
			}
		}
	}

	cout << n << endl;
}

// Subiectul 3

// Problema 2
// Subprogramul patrat are un parametru n, prin care
// primeste un numar natural.
// Subprogramul returneaza cel mai mare patrat perfect care este
// divizor al lui n.

int patrat(int n) {
	for (int i = sqrt(n); i > 0; i--) {
		int k = pow(i, 2);
		if (n % k == 0) {
			return k;
		}
	}
	return 0;
}

void rezolvareSub3Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << patrat(n);
}

// Problema 3
// Se citeste din fisier un sir S.
// Sa se afiseze numarul de elemente din sir
// care au un numar maxim de "0" la finalul factorialului
// lor si care este acest numar.

// ? ? ? ?

void rezolvareSub3Problema3() {

}