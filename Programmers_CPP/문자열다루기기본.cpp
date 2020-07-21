#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	for (char c : s) {
		if (!('0' <= c && '9' >= c))
			return false;
	}
	if (s.length() == 4 || s.length() == 6)
		return true;
	else
		return false;
}