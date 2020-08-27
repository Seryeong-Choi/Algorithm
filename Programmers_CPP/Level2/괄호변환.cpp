#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string p) {
	string ans = "";
	if (p.length() == 0)
		return ans;

	int cnt = 0;
	int index;
	bool chk = true;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')
			cnt++;
		else
			cnt--;
		if (cnt < 0)
			chk = false;
		else if (cnt == 0) {
			index = i;
			break;
		}
	}
	string u = p.substr(0, index + 1);
	string v = p.substr(index + 1, p.length() - index);

	if (chk)
		ans = u + solution(v);
	else {
		ans += '(' + solution(v) + ')';
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(')
				ans += ')';
			else
				ans += '(';
		}
	}
	return ans;
}