#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
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

	int ans = 0;
	vector<int> check(26, 0);//a부터 z까지 check, 0으로 초기화 
	// -1: 그룹단어 아님 0:존재하지 않음 1:그룹단어
	for (int i = 0; i < n; i++){
		for (int j = 0; j < words[i].length(); j++) {
			if (check[words[i][j] - 'a'] != -1) {
				//j==0일때
				if (j == 0 && check[words[i][j] - 'a'] == 0)
					check[words[i][j] - 'a'] = 1;
				else if(j == 0 && check[words[i][j] - 'a'] == 1)
					check[words[i][j] - 'a'] = -1;
				//j!=0일때
				else if (words[i][j] != words[i][j - 1] && check[words[i][j] - 'a'] == 0)
					check[words[i][j] - 'a'] = 1;
				else if (words[i][j] != words[i][j - 1] && check[words[i][j] - 'a'] == 1)
					check[words[i][j] - 'a'] = -1;
			}
		}
		if (find(check.begin(),check.end(),-1) == check.end())
			ans++;
		fill(check.begin(), check.end(), 0);
	}
	cout << ans;
}