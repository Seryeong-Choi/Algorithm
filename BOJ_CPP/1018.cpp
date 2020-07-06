#include <iostream>
#include <algorithm>
using namespace std;

int solve();
int main() {
	cout << solve();
	return 0;
}

int solve() {
	char white[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1)))
				white[i][j] = 'W';
			else
				white[i][j] = 'B';
		}
	}

	char black[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1)))
				black[i][j] = 'B';
			else
				black[i][j] = 'W';
		}
	}

	int n, m;

	cin >> n >> m;

	char** chess = new char* [n];
	for (int i = 0; i < n; i++)
		chess[i] = new char[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}

	int Min = 64;
	int tempB = 0;
	int tempW = 0;

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (chess[i + k][j + l] != black[k][l])
						tempB++;
					if (chess[i + k][j + l] != white[k][l])
						tempW++;
				}
			}
			if (min(tempB, tempW) < Min)
				Min = min(tempB, tempW);

			tempB = 0;
			tempW = 0;
		}
	}
	return Min;
}