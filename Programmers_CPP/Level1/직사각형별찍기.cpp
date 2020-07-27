#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	string str = "";
	for (int i = 0; i < n; i++)
		str += '*';

	vector<string> stars(m, str);

	for (int i = 0; i < m; i++)
		cout << stars[i] << endl;

	return 0;
}