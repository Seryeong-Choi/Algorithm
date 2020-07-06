#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void input();
void avg(int* arr, int n);
void middle(int* arr, int n);
void frequent(int* arr, int n);
void range(int* arr, int n);

int main() {
	input();

	return 0;
}

void input() {
	int n = 1;

	cin >> n;

	int* num = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	avg(num, n);
	middle(num, n);
	frequent(num, n);
	range(num, n);
}

void avg(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	int avg = round((float)sum / n);
	cout << avg << endl;
}

void middle(int* arr, int n) {
	cout << arr[(n - 1) / 2] << endl;
}

void frequent(int* arr, int n) {
	int* fre = new int[8001];
	fill(fre, fre + 8001, 0);

	int max = 0;
	int index = 0;

	for (int i = 0; i < n; i++) {
		fre[arr[i] + 4000]++;
		if (fre[arr[i] + 4000] >= max) {
			max = fre[arr[i] + 4000];
			index = arr[i] + 4000;
		}
	}

	int count = 0;
	for (int i = 0; i < index + 4001; i++) {
		if (fre[i] == max) {
			count++;
			if (count == 2)
				cout << i - 4000 << endl;
		}
	}

	if (count == 1)
		cout << index - 4000 << endl;
}

void range(int* arr, int n) {
	cout << arr[n - 1] - arr[0] << endl;
}