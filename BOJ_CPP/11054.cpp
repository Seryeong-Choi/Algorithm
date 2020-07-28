#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> num(n, 0);
	vector<int> dpFront(n, 1);
	vector<int> dpEnd(n, 1);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	int temp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (num[j] < num[i])
				temp = max(dpFront[j], temp);
		dpFront[i] += temp;
		temp = 0;
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--)
			if (num[i] > num[j])
				temp = max(dpEnd[j], temp);
		dpEnd[i] += temp;
		temp = 0;
	}

	for (int i = 0; i < n; i++)
		dpFront[i] += dpEnd[i];

	cout << *max_element(dpFront.begin(), dpFront.end()) - 1;
}