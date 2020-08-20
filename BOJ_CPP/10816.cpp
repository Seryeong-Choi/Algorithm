#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, mid, target;
vector<int> card;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		card.push_back(temp);
	}
	sort(card.begin(), card.end());

	cin >> m;
	//output
	for (int i = 0; i < m; i++) {
		cin >> target;
		cout << upper_bound(card.begin(), card.end(), target) - lower_bound(card.begin(), card.end(), target) << ' ';
	}
}