#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit(9, false);
vector<int> arr;
int n, m;

void backtracking(int index) {
	if (index == m) {
		for (int i : arr) {
			cout << i << " ";
		}
		cout << "\n";
	}
	else if (index == 0) {
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {// 방문하지 않았으면
				visit[i] = true;
				arr[index] = i;
				backtracking(index + 1);
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && arr[index - 1] < i) {// 방문하지 않았으면
				visit[i] = true;
				arr[index] = i;
				backtracking(index + 1);
				visit[i] = false;
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
	arr.assign(m, 0);

	backtracking(0);
}