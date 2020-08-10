#include <iostream>
#include <math.h>
using namespace std;

int startlink[20][20], teamA[10] = { 0 }, teamB[10];
int n, minValue, tempA, tempB;
bool initiate = true;

void backtracking(int index, int Asize, int Bsize){//, int now[]) {
	if (index == n) {
		tempA = 0, tempB = 0;
		for (int i = 0; i < n / 2 - 1; i++)
			for (int j = i + 1; j < n / 2; j++) {
				tempA += startlink[teamA[i]][teamA[j]];
				tempA += startlink[teamA[j]][teamA[i]];
				tempB += startlink[teamB[i]][teamB[j]];
				tempB += startlink[teamB[j]][teamB[i]];
			}
		tempA = abs(tempA - tempB);
		
		if (initiate) {
			minValue = tempA;
			initiate = false;
		}
		else if (tempA < minValue)
			minValue = tempA;
	}

	else {
		if (Asize < n / 2) {
			teamA[Asize] = index;
			backtracking(index + 1, Asize + 1, Bsize);
			teamA[Asize] = 0;
		}
		if (Bsize < n / 2) {
			teamB[Bsize] = index;
			backtracking(index + 1, Asize, Bsize + 1);
			teamB[Bsize] = 0;
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
		for (int j = 0; j < n; j++)
			cin >> startlink[i][j];
	//backtracking
	backtracking(1,1,0);//, { 0 });
	//output
	cout << minValue;
}