#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
	if (n % m == 0) return m;
	else return gcd(m, n % m);
}

int lcm(int n, int m) {
	return n * m / gcd(n, m);
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	if (n > m) {
		answer.push_back(gcd(n, m));
		answer.push_back(lcm(n, m));
	}
	else {
		answer.push_back(gcd(m, n));
		answer.push_back(lcm(m, n));
	}
	return answer;
}