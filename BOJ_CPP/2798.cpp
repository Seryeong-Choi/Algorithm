#include <iostream>
using namespace std;

int blackjack(int n, int m, int* cards);

int main()
{
	int n, m;
	cin >> n >> m;

	int* cards = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	cout << blackjack(n, m, cards);
	return 0;
}

int blackjack(int n, int m, int* cards) {
	int result = 0;
	int temp = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				temp = cards[i] + cards[j] + cards[k];

				if (temp <= m && temp > result) {
					result = temp;
				}
			}
		}
	}
	return result;
}