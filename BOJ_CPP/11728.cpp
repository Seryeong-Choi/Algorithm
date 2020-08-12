#include <iostream>
#include <vector>
using namespace std;

int n, m, arrA[1000000], arrB[1000000];
vector<int> ans;

void sort() {
	int indexA = 0, indexB = 0;
	while (indexA < n && indexB < m)
		if (arrA[indexA] < arrB[indexB])
			ans.push_back(arrA[indexA++]);
		else
			ans.push_back(arrB[indexB++]);

	while (indexA < n)
		ans.push_back(arrA[indexA++]);

	while (indexB < m)
		ans.push_back(arrB[indexB++]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arrA[i];
	for (int i = 0; i < m; i++)
		cin >> arrB[i];

	//sort
	sort();
	//output
	for (int i = 0; i < n + m; i++)
		cout << ans[i] << " ";
}