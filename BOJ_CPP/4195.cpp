#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> level;
map<string, string> parent;
string find(string node) {
	if (parent[node] == node)
		return node;
	else
		return parent[node] = find(parent[node]);
}

int merge(string n1, string n2) {
	if (n1 == n2)
		return level[n1];
	else if (level[n1] < level[n2]) {
		parent[n1] = n2;
		level[n2] += level[n1];
		return level[n2];
	}
	else {
		parent[n2] = n1;
		level[n1] += level[n2];
		return level[n1];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	string temp, s1, s2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		level.clear();
		parent.clear();
		for (int j = 0; j < n; j++) {
			cin >> s1 >> s2;
			if (level.find(s1) == level.end()) {
				level.insert({ s1, 1 });
				parent.insert({ s1, s1 });
			}
			if (level.find(s2) == level.end()) {
				level.insert({ s2, 1 });
				parent.insert({ s2, s2 });
			}
			string par_s1 = find(s1);
			string par_s2 = find(s2);
			cout << merge(par_s1, par_s2) << '\n';
		}
	}
}