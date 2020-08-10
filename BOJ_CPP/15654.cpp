#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
vector<bool> visit(8, false);
int print[8];

void backtracking(int index) { 
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << print[i] << " ";
		cout << "\n";
	}

	else {
		if (index < m) 
			for (int i = 0 ; i < n ; i++)
				if (!visit[i]) {
					visit[i] = true;
					print[index] = num[i];
					backtracking(index + 1);
					visit[i] = false;
				}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	//backtracking
	sort(num.begin(), num.end());
	backtracking(0);
}