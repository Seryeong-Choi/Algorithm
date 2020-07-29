#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string str1, str2;
	cin >> str1 >> str2;

	vector<vector<int>> lcs(str1.length()+1, vector<int>(str2.length()+1, 0));
	
	for (int i = 1; i < str1.length() + 1; i++) {
		for (int j = 1; j < str2.length() + 1; j++) {
			if (str1[i - 1] == str2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[str1.length()][str2.length()];
}