#include <iostream>
using namespace std;

int num[11], oper[4]; //0:+ 1:- 2:* 3:/
int n, minValue, maxValue;
bool initiate = true;

void backtracking(int index, int now) {
	if (index == n) {
		if (initiate) {
			minValue = now;
			maxValue = now;
			initiate = false;
		}
		else {
			if (now > maxValue)
				maxValue = now;
			else if (now < minValue)
				minValue = now;
		}
	}

	else {
		if (oper[0] != 0) {
			oper[0]--;
			backtracking(index + 1, now + num[index]);
			oper[0]++;
		}
		if (oper[1] != 0) {
			oper[1]--;
			backtracking(index + 1, now - num[index]);
			oper[1]++;
		}
		if (oper[2] != 0) {
			oper[2]--;
			backtracking(index + 1, now * num[index]);
			oper[2]++;
		}
		if (oper[3] != 0) {
			oper[3]--;
			backtracking(index + 1, now / num[index]);
			oper[3]++;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	//backtracking
	backtracking(1, num[0]);
	//output
	cout << maxValue << "\n" << minValue;
}