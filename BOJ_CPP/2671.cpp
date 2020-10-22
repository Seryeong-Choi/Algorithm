#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input_s;
	cin >> input_s;
	
	regex re("(100+1+|(01)+)+");
	smatch match;
	regex_match(input_s, match, re);
	if (match.length() == input_s.length())
		cout << "SUBMARINE";
	else cout << "NOISE";
}