#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> key(10, 1);
	int target, m;
	cin >> target >> m;
	int temp;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		key[temp] = 0;
	}

	//처음 채널인 100과 비교
	int min_n = abs(target - 100);
	temp = target;
	//타겟 확인
	int sum = 0;
	string s = to_string(target);
	for (int j = 0; j < s.length(); j++)
		sum += key[s[j] - '0'];
	if (sum == s.length())
		min_n = min(min_n, (int)s.length());
	//위쪽 비교
	for (int i = 0; i < min_n; i++) {
		sum = 0;
		temp++;
		string s = to_string(temp);
		for (int j = 0; j < s.length(); j++)
			sum += key[s[j] - '0'];
		if (sum == s.length())
			break;
	}
	min_n = min(min_n, (int)(abs(temp - target) + to_string(temp).length()));
	//아래쪽 비교
	temp = target;
	for (int i = 0; i < min_n; i++) {
		sum = 0;
		temp--;
		if (temp < 0) // 채널은 양수만 있음
			break;
		string s = to_string(temp);
		for (int j = 0; j < s.length(); j++)
			sum += key[s[j] - '0'];
		if (sum == s.length())
			break;
	}
	if (temp >= 0) // 음수일떄 break된 경우 제외
		min_n = min(min_n, (int)(abs(temp - target) + to_string(temp).length()));

	cout << min_n;
}