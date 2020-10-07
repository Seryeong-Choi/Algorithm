#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string now;
int l, c;
vector<char> vowel = { 'a','e','i','o','u' };
vector<char> password;
void solution(int index, int cnt, int vow, int con) {
	if (cnt == l && vow > 0 && con > 1)
		cout << now << '\n';
	else if (index == c)
			return;
	else {
		for (int i = index; i < c; i++) {
			now += password[i];
			if (find(vowel.begin(), vowel.end(), password[i]) == vowel.end())
				solution(i + 1, cnt + 1, vow, con + 1);
			else
				solution(i + 1, cnt + 1, vow + 1, con);
			now = now.substr(0, now.length() - 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> l >> c;
	password.assign(c, 0);
	for (int i = 0; i < c; i++)
		cin >> password[i];
	sort(password.begin(), password.end());
	solution(0, 0, 0, 0);
}