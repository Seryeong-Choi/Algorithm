#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	else return s1.length() < s2.length();
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> words_size, answer;
	sort(words.begin(), words.end(), compare);
	vector<string> words_r = words;
	for (string& s : words_r)
		reverse(s.begin(), s.end());
	sort(words_r.begin(), words_r.end(), compare);

	for (string& q : queries) {
		int start = 0, end, lower, upper;
		int len = q.length();
		string query, q1, q2;
		
		if (q[0] == '?') {
			reverse(q.begin(), q.end());
			end = q.find_first_of('?') - 1;
			query = q.substr(start, end - start + 1);
			q1 = query;
			q2 = query;
			for (int i = end + 1; i < len; i++) {
				q1 += 'a';
				q2 += 'z';
			}
			lower = lower_bound(words_r.begin(), words_r.end(), q1, compare) - words_r.begin();
			upper = upper_bound(words_r.begin(), words_r.end(), q2, compare) - words_r.begin();
		}
		else {
			end = q.find_first_of('?') - 1;
			query = q.substr(start, end - start + 1);
			q1 = query;
			q2 = query;
			for (int i = end + 1; i < len; i++) {
				q1 += 'a';
				q2 += 'z';
			}
			lower = lower_bound(words.begin(), words.end(), q1, compare) - words.begin();
			upper = upper_bound(words.begin(), words.end(), q2, compare) - words.begin();
		}
		answer.push_back(upper - lower);
	}
	return answer;
}