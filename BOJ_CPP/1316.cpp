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
	vector<int> check(26, 0);//a���� z���� check, 0���� �ʱ�ȭ 
	// -1: �׷�ܾ� �ƴ� 0:�������� ���� 1:�׷�ܾ�
	for (int i = 0; i < n; i++){
		for (int j = 0; j < words[i].length(); j++) {
			if (check[words[i][j] - 'a'] != -1) {
				//j==0�϶�
				if (j == 0 && check[words[i][j] - 'a'] == 0)
					check[words[i][j] - 'a'] = 1;
				else if(j == 0 && check[words[i][j] - 'a'] == 1)
					check[words[i][j] - 'a'] = -1;
				//j!=0�϶�
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