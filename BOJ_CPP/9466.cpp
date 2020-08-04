#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> student(100001);
vector<int> dist(100001);
int n, team;

void dfs(int n) {
	vector<int> s; //stack
	s.push_back(n);
	dist[n] = 1;

	while (!s.empty()) {
		n = s.back();
		if (dist[student[n]] == 0){
			dist[student[n]] = dist[n] + 1;
			s.push_back(student[n]);
		}
		else {
			if (find(s.begin(), s.end(), student[n]) != s.end())//stack에 존재하는지 확인
				team += dist[n] - dist[student[n]] + 1;
			s.clear();
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0 ; i < t ; i++) {
		//초기화
		fill(dist.begin(), dist.end(), 0);
		team = 0;
		
		cin >> n;
		for (int j = 1 ; j <= n ; j++)
			cin >> student[j];

		for (int j = 1 ; j < n + 1 ; j++)
			if (dist[j] == 0)
				dfs(j);

		cout << n - team << "\n";
	}
}