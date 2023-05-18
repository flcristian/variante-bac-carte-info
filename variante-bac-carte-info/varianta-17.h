#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	char x[100][100];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			x[i][j] = 'A' + (5 - i + j) % 5;
			cout << x[i][j];

			cout << " ";
			if (j == 4) {
				cout << endl;
			}
		}
	}
}

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {

}

// Problema 2

void rezolvareSub3Problema2() {

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

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
}