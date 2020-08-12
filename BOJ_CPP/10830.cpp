#include <iostream>
#include <vector>
using namespace std;

int n;
long long b;
typedef vector<vector<int>> matrix;
matrix input(5, vector<int>(5, 0)), ans(5, vector<int>(5,0)), m(5, vector<int>(5, 0));

matrix square(long long b) {
	if (b == 1)
		return input;

	else if (b % 2 == 0) {
		m = square(b / 2);
		ans.assign(5, vector<int>(5, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)  
				for (int a = 0; a < n; a++) {
					ans[i][j] += (m[i][a] * m[a][j]) % 1000;
					ans[i][j] %= 1000;
				}
		return ans;
	}

	else {
		m = square(b - 1);
		ans.assign(5, vector<int>(5, 0));
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++)
				for (int a = 0; a < n; a++) {
					ans[i][j] += (input[i][a] * m[a][j]) % 1000;
					ans[i][j] %= 1000;
				}
		return ans;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> b;
	for (int i = 0 ; i < n ; i++)
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
			input[i][j] %= 1000;
		}
	//dac
	ans = square(b);
	//output
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
}