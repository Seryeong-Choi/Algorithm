#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	if (n % 2 != 0)
		answer++;
	for (int i = 1; i < n; i++) {
		if (i % 2 != 0 && n % i == 0)
			answer++;
	}

	return answer;
}