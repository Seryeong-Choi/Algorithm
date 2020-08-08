#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, m;

void backtracking(int index) {
	if (index == m) {
		for (int i : arr) {
			cout << i << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = 1 ; i <= n ; i++) {
			if (index == 0 || arr[index-1] <= i) {
				arr[index] = i;
				backtracking(index + 1);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input

	cin >> n >> m;
	arr.assign(m,0);

	backtracking(0);
}