#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> tomato(1000, vector<int>(1000,-1));
vector<vector<int>> pos = { {0,-1},{1,0},{0,1},{-1,0} };
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int n, m;

bool isValid(int x, int y) { // check index
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

void oneStep() { //bfs
	while (!q1.empty()) {
		int x = q1.front().first;
		int y = q1.front().second;
		int a, b;
		for (int i = 0; i < 4; i++) {
			a = x + pos[i][0];
			b = y + pos[i][1];
			if (isValid(a, b) && tomato[a][b] == 0) {
				tomato[a][b] = 1;
				q2.push(make_pair(a, b));
			}
		}
		q1.pop();
	}
	swap(q1, q2);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> m >> n;

	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				q1.push(make_pair(i, j));
		}
	//bfs
	int count = 0;
	while (!q1.empty() || !q2.empty()) {
		oneStep();
		count++;
	}
	//print result 
	bool ans = true;
	for (int i = 0 ; i < n; i++) {
		if (find(tomato[i].begin(), tomato[i].end(), 0) != tomato[i].end()) {
			ans = false;
			cout << -1;
			break;
		}
	}
	if (count == 0 && ans == true)
		cout << count;
	else if (ans == true)
		cout << count - 1; //불필요한 마지막 탐색 1회 제거
}