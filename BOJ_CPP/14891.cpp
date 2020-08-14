#include <iostream>
#include <string>
using namespace std;

int wheels[4][8], rotation[100][2];
int rightW = 2, leftW = 6; //오른쪽톱니 인덱스, 왼쪽톱니 인덱스
int n, k, temp;
bool checkPole[4];//회전여부 체크

void counterclockwise(int index) {
	temp = wheels[index][0];
	for (int i = 1; i < 8; i++)
		wheels[index][i - 1] = wheels[index][i];
	wheels[index][7] = temp;
}

void clockwise(int index) {
	temp = wheels[index][7];
	for (int i = 7; i > 0; i--)
		wheels[index][i] = wheels[index][i - 1];
	wheels[index][0] = temp;
}

void compare(int base) { //바퀴별 회전여부 체크
	fill(begin(checkPole), end(checkPole), false);
	checkPole[base] = true;
	
	if (base == 0) {
		if (wheels[0][rightW] != wheels[1][leftW]) {
			checkPole[1] = true;
			if (wheels[1][rightW] != wheels[2][leftW]) {
				checkPole[2] = true;
				if (wheels[2][rightW] != wheels[3][leftW]) {
					checkPole[3] = true;
				}
			}
		}
	}
	else if (base == 1) {
		if (wheels[1][leftW] != wheels[0][rightW])
			checkPole[0] = true;
		if (wheels[1][rightW] != wheels[2][leftW]) {
			checkPole[2] = true;
			if (wheels[2][rightW] != wheels[3][leftW])
				checkPole[3] = true;
		}
	}
	else if (base == 2) {
		if (wheels[2][rightW] != wheels[3][leftW])
			checkPole[3] = true;
		if (wheels[2][leftW] != wheels[1][rightW]) {
			checkPole[1] = true;
			if (wheels[1][leftW] != wheels[0][rightW])
				checkPole[0] = true;
		}
	}
	else if (base == 3) {
		if (wheels[3][leftW] != wheels[2][rightW]) {
			checkPole[2] = true;
			if (wheels[2][leftW] != wheels[1][rightW]) {
				checkPole[1] = true;
				if (wheels[1][leftW] != wheels[0][rightW]) {
					checkPole[0] = true;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	string temp;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 0; j < 8; j++)
			wheels[i][j] = temp[j] - '0';
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> rotation[i][0] >> rotation[i][1];
		rotation[i][0]--;
	}
	//rotating
	for (int i = 0; i < k; i++) {
		if ((rotation[i][1] == 1 && rotation[i][0] % 2 == 0) //짝수시계 홀수반시계
			|| (rotation[i][1] == -1 && rotation[i][0] % 2 == 1)) {
			compare(rotation[i][0]);
			if (checkPole[0])
				clockwise(0);
			if (checkPole[1])
				counterclockwise(1);
			if (checkPole[2])
				clockwise(2);
			if (checkPole[3])
				counterclockwise(3);
		}

		else { //홀수시계 짝수반시계
			compare(rotation[i][0]);
			if (checkPole[0])
				counterclockwise(0);
			if (checkPole[1])
				clockwise(1);
			if (checkPole[2])
				counterclockwise(2);
			if (checkPole[3])
				clockwise(3);
		}
	}
	//result
	int ans = 0;
	if (wheels[0][0] == 1)
		ans += 1;
	if (wheels[1][0] == 1)
		ans += 2;
	if (wheels[2][0] == 1)
		ans += 4;
	if (wheels[3][0] == 1)
		ans += 8;

	cout << ans;
}