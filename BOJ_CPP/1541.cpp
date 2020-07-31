#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	vector<int> num;
	string tempS = "";
	int tempI = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			tempS += s[i];
		else if (s[i] == '+') {
			tempI += stoi(tempS);
			tempS = "";
		}
		else if (s[i] == '-') {
			tempI += stoi(tempS);
			num.push_back(tempI);
			tempS = "";
			tempI = 0;
		}
	}
	tempI += stoi(tempS);
	num.push_back(tempI);

	int ans = num[0];
	for (int i = 1; i < num.size(); i++)
		ans -= num[i];

	cout << ans;
}