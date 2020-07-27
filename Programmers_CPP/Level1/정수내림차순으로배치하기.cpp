#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	vector<int> temp;
	while (n > 0) {
		temp.push_back(n % 10);
		n /= 10;
	}
	sort(temp.begin(), temp.end(), greater<int>());
	for (int i : temp) {
		answer *= 10;
		answer += i;
	}
	return answer;
}