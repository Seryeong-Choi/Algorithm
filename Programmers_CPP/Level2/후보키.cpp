#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct s_data {
	int index;
	string key;
};

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int row = relation.size();
	int column = relation[0].size();
	queue<s_data> q;
	vector<string> candidate;
	s_data front;
	set<string> s;

	for (int i = 0; i < column; i++) {
		s.clear();
		for (int j = 0; j < row; j++)
			s.insert(relation[j][i]);
		if (s.size() == row) {
			answer++;
			candidate.push_back(to_string(i));
		}
		else
			q.push({ i + 1, to_string(i) });
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = front.index; i < column; i++) {
			string str = front.key + to_string(i);
			bool flag = true;
			for (string s : candidate)
				if (includes(str.begin(), str.end(), s.begin(), s.end())) {
					flag = false;
					break;
				}
			if (flag) {
				s.clear();
				for (int j = 0; j < row; j++) {
					string temp;
					for (char c : str)
						temp += relation[j][c - '0'];
					s.insert(temp);
				}
				if (s.size() == row) {
					answer++;
					candidate.push_back(str);
				}
				else
					q.push({ i + 1, str });
			}
		}
	}
	return answer;
}