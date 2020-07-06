#include <iostream>
using namespace std;

void solve();
int main() {
	solve();
	return 0;
}

void solve() {
	int n = 2;
	int count = 0;

	cin >> n;

	int** array;
	array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[2];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			cin >> array[i][j];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (array[j][0] > array[i][0] && array[j][1] > array[i][1])
				count++;
		}
		cout << count + 1 << " ";
		count = 0;
	}

	for (int i = 0; i < n; i++) {
		delete[] array[i];
	}
	delete[] array;
}