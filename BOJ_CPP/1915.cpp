#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	string str;
	vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++)
			matrix[i][j] = (int)(str[j - 1] - '0');
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (matrix[i][j] == 1) {
				if (matrix[i - 1][j] >= 1 && matrix[i][j - 1] >= 1 && matrix[i - 1][j - 1] >= 1)
					matrix[i][j] = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1])) + 1;
				ans = max(matrix[i][j], ans);
			}
		}
	cout << ans * ans;
}