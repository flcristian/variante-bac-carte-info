#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
		}
	}

	// ? ? ? ? ? ? ?
}

// Subiectul 3

// Problema 1

void invers(char s[], char i[]) {
	for (int k = strlen(s) - 1, j = 0; k > -1; k--, j++) {
		i[j] = s[k];
	}
}

void rezolvareSub3Problema1() {
	char s[100] = "";
	cin.getline(s, 100);
	char i[100] = "";
	invers(s, i);
	strcat(s, i + 1);
	cout << s;
}

// Problema 2

void eliminarePos(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void compact(int x[], int& n) {
	for (int i = 1; i < n; i++) {
		if (x[i] == x[i - 1]) {
			eliminarePos(x, n, i);
			i--;
		}
	}
}

void rezolvareSub3Problema2() {
	int x[100] = { 1,2,2,2,3,3,5,8,9 }, n = 9;
	compact(x, n);
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
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

void secventaV(int x[], int n, int& max, int& count) {
	bool down = 1, r = 0;
	max = 0, count = 0;
	int c = 0;
	for (int i = 1; i < n; i++) {	
		if ((x[i] < x[i - 1] && down) || x[i] > x[i - 1] && !down) {
			c++;
			if (c > max) {
				max = c;
				count = 0;
			}
			if (c == max) {
				count++;
			}
		}
		else {
			if (r == 0 && c > 1) {
				down = false;
				c++;
				r++;
			}
			else {
				down = true;
				r = 0;
				c = 1;				
			}
		}
	}
	
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireProblema3(x, n);
	int max, count;
	secventaV(x, n, max, count);
	cout << max << " " << count;
}