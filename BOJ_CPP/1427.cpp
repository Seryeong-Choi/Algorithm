#include <iostream>
#include <algorithm>
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

	int arr[10];
	fill(arr, arr + 10, 0);

	int i = 0;
	while (n > 0) {
		arr[i] = n % 10;
		n = n / 10;
		i++;
	}

	int count = i;

	sort(arr, arr + 10);

	for (int i = 9; i >= 10 - count; i--)
		cout << arr[i];
}