#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int Lpos = 10;
	int Rpos = 12;

	for (int i : numbers) {
		if (i == 0)
			i = 11;

		if (i == 1 || i == 4 || i == 7) {
			answer += 'L';
			Lpos = i;
		}
		else if (i == 3 || i == 6 || i == 9) {
			answer += 'R';
			Rpos = i;
		}
		else {
			int L = abs((Lpos - 1) / 3 - (i - 1) / 3) + abs((Lpos - 1) % 3 - (i - 1) % 3);
			int R = abs((Rpos - 1) / 3 - (i - 1) / 3) + abs((Rpos - 1) % 3 - (i - 1) % 3);
			if (L < R || (L == R && hand == "left")) {
				answer += 'L';
				Lpos = i;
			}
			else {
				answer += 'R';
				Rpos = i;
			}
		}
	}
	return answer;
}