#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pos;
typedef vector<vector<int>> arr;
int n, m, ans = 64;
vector<pos> cctv;
arr office(8, vector<int>(8, 0)), w(8, vector<int>(8)), previous[64];

void east(int x, int y) {
	for (int i = y + 1; i < m; i++) {
		if (w[x][i] == 0)
			w[x][i] = 7;
		else if (w[x][i] == 6)
			break;
	}
}

void west(int x, int y) {
	for (int i = y - 1; i >= 0; i--) {
		if (w[x][i] == 0)
			w[x][i] = 7;
		else if (w[x][i] == 6)
			break;
	}
}

void south(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (w[i][y] == 0)
			w[i][y] = 7;
		else if (w[i][y] == 6)
			break;
	}
}

void north(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (w[i][y] == 0)
			w[i][y] = 7;
		else if (w[i][y] == 6)
			break;
	}
}

void solution(int index) {
	if (index == cctv.size()) {
		int temp = n * m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (w[i][j] != 0)
					temp--;
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << w[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		*/
		ans = min(ans, temp);
	}

	else {
		previous[index] = w;
		////////
		if (w[cctv[index].first][cctv[index].second] == 1) {
			east(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];//초기화 방법?

			west(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			south(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			north(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];
		}
		/////////
		else if (w[cctv[index].first][cctv[index].second] == 2) {
			east(cctv[index].first, cctv[index].second);
			west(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			south(cctv[index].first, cctv[index].second);
			north(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];
		}
		//////
		else if (w[cctv[index].first][cctv[index].second] == 3) {
			east(cctv[index].first, cctv[index].second);
			south(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			south(cctv[index].first, cctv[index].second);
			west(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			west(cctv[index].first, cctv[index].second);
			north(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			north(cctv[index].first, cctv[index].second);
			east(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];
		}
		////
		else if (w[cctv[index].first][cctv[index].second] == 4) {
			east(cctv[index].first, cctv[index].second);
			south(cctv[index].first, cctv[index].second);
			west(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			south(cctv[index].first, cctv[index].second);
			west(cctv[index].first, cctv[index].second);
			north(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			west(cctv[index].first, cctv[index].second);
			north(cctv[index].first, cctv[index].second);
			east(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];

			north(cctv[index].first, cctv[index].second);
			east(cctv[index].first, cctv[index].second);
			south(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];
		}
		/////
		else if (w[cctv[index].first][cctv[index].second] == 5) {
			east(cctv[index].first, cctv[index].second);
			south(cctv[index].first, cctv[index].second);
			west(cctv[index].first, cctv[index].second);
			north(cctv[index].first, cctv[index].second);
			solution(index + 1);
			w = previous[index];
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6)
				cctv.push_back({ i, j });
		}
	cout << endl; 
	w = office;
	solution(0);

	cout << ans;
}
/*
4 6
0 0 0 0 4 0
0 0 0 0 0 0
0 0 2 0 6 0
0 0 0 0 0 0

4 4
0 0 0 1
0 0 0 0
0 1 0 0
0 0 0 0
*/