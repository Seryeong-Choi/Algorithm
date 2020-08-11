#include <iostream>
using namespace std;

#define MAX 2187
int n, paper[MAX][MAX];
int ans[3] = { 0,0,0 };
bool stop = true;

void countPaper(int x, int y, int n) {
	stop = true;
	for (int i = x ; i < x + n ; i++)
		for (int j = y ; j < y + n ; j++)
			if (paper[i][j] != paper[x][y])
				stop = false;

	if (stop)
		ans[paper[x][y] + 1]++;
		
	else {
		countPaper(x, y, n / 3);
		countPaper(x, y + n / 3, n / 3);
		countPaper(x, y + n * 2 / 3, n / 3);
		countPaper(x + n / 3, y, n / 3);
		countPaper(x + n / 3, y + n / 3, n / 3);
		countPaper(x + n / 3, y + n * 2 / 3, n / 3);
		countPaper(x + n * 2 / 3, y, n / 3);
		countPaper(x + n * 2 / 3, y + n / 3, n / 3);
		countPaper(x + n * 2 / 3, y + n * 2 / 3, n / 3);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	//divide and conquer
	countPaper(0, 0, n);
	//output
	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}