#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos {
	int x, y;
};
int n, m, city[50][50], ans = 1000000;
vector<pos> chicken, house;

void solution(int index, int count, vector<int> del) {
	if (count == m) {
		vector<pos> t_chicken = chicken;
		for (int i = del.size() - 1; i >= 0; i--) 
			t_chicken.erase(t_chicken.begin()+del[i]);

		int chicken_dist = 0;
		for (pos p : house) {
			int t = n * 2;
			for (pos c : t_chicken)
				t = min(t, abs(p.x - c.x) + abs(p.y - c.y));
			chicken_dist += t;
		}
		ans = min(ans, chicken_dist);
	}
	else {
		for (int i = index; i < chicken.size(); i++) {
			del.push_back(i);
			solution(i + 1, count + 1, del);
			del.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back({ i,j });
			else if (city[i][j] == 2)
				chicken.push_back({ i,j });
		}
	m = chicken.size() - m;

	vector<int> del;
	solution(0, 0, del);

	cout << ans;
}