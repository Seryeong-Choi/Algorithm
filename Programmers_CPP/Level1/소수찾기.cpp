#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> prime(n + 1);
	fill(prime.begin(), prime.end(), 1);
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i < sqrt(n); i++) {
		for (int j = 2; j <= n / i; j++)
			if (prime[j * i] != 0)
				prime[j * i] = 0;
	}
	for (int i : prime)
		answer += i;

	return answer;
}