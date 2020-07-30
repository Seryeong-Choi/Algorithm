#include <iostream>
#include <string>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int ans = s.length();

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '=' && i > 1 && s[i - 1] == 'z' && s[i - 2] == 'd')
			ans -= 2;
		else if (s[i] == '=' || s[i] == '-')
			ans--;
		else if (s[i] == 'j' && (s[i - 1] == 'l' || s[i - 1] == 'n'))
			ans--;
	}
	cout << ans;
}
