#include <iostream>
using namespace std;

void countingSort();

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	countingSort();

	return 0;
}

void countingSort() {
	int n = 1;

	cin >> n;

	int temp = 0;

	int countSum[10001];
	fill(countSum, countSum + 10001, 0);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		countSum[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (countSum[i] != 0) {
			for (int j = 0; j < countSum[i]; j++)
				cout << i << "\n";
		}
	}
}