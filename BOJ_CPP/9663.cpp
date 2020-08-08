#include <iostream>
#include <vector>
using namespace std;

int board[15];
int nextboard[15];
int n, ans = 0;
bool check;

void nqueen(int count, int board[]) {
	if (count == n)
		ans++;

	else {
		for (int i = 0; i < n; i++) {
			check = true;
			for (int j = 1 ; j <= count; j++) {
				if (i == board[count - j] + j || i == board[count - j] - j || i == board[count - j]) {
					check = false;
					break;
				}
			}

			if (check) {
				for (int j = 0; j < count; j++)
					nextboard[j] = board[j];
				nextboard[count] = i;

				nqueen(count + 1, nextboard);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	//backtracking
	nqueen(0, board);
	//output
	cout << ans;
}