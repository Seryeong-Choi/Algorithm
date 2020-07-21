#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
	int a = (int)sqrt(n);
	if (a * a == n)
		answer -= a;

	for (int i = 1; i <= sqrt(n); i++)
		if (n % i == 0) {
			answer += i;
			answer += n / i;
		}
	return answer;
}