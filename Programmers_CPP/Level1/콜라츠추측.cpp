#include <vector>

using namespace std;

int solution(int num) {
	int answer = 0;
	long long lnum = (long long)num;
	while (lnum != 1 && answer < 501) {
		if (lnum % 2 == 0) {
			lnum /= 2;
			answer++;
		}
		else {
			lnum = lnum * 3 + 1;
			answer++;
		}
	}
	if (answer == 501) return -1;
	else return answer;
}