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

// Problema 1

void rezolvareSub3Problema1() {

}

// Problema 2

void rezolvareSub3Problema2() {

}

// Problema 3

void rezolvareSub3Problema3() {

}