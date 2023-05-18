#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 1

// Problema 3

void rezolvareSub1Problema3() {

}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {

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