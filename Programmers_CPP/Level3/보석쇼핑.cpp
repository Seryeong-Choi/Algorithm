#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> ans = { 0, 99999, 99999 };
	set<string> gs;
	for (string s : gems)
		gs.insert(s);
	int variety = gs.size();

	int left = 0;
	int right = 0;
	unordered_map <string, int> m;
	for (string s : gs)
		if (m.find(s) == m.end())
			m.insert({ s, 0 });

	int chk_size = 0;
	while (left <= right && right < gems.size()) {
		if (chk_size == variety) {
			if (m[gems[left]] == 1) {
				if (ans[2] > right - left)
					ans = { left, right, right - left };
				chk_size--;
				right++;
			}
			--m[gems[left++]];
		}
		else {
			if (m[gems[right]] == 0) {
				chk_size++;
				m[gems[right]]++;
				if (chk_size == variety) {
					if (ans[2] > right - left)
						ans = { left, right, right - left };
				}
				else
					right++;
			}
			else
				++m[gems[right++]];
		}
	}
	return { ans[0] + 1, ans[1] + 1 };
}