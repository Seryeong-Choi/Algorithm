#include <string>

using namespace std;

bool solution(int x) {
	string sx = to_string(x);
	int sum = 0;
	for (char c : sx)
		sum += c - '0';

	if (x % sum == 0) return true;
	else return false;
}