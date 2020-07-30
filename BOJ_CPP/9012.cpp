#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> words;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		words.push_back(temp);
	}

	int check = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			if (words[i][j] == '(')
				check++;
			else
				check--;

			if (check < 0)
				break;
		}
		if (check != 0) {
			cout << "NO\n";
		}
		else
			cout << "YES\n";
		check = 0;
	}
}