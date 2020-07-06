#include <iostream>
using namespace std;

void han();
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	han();

	return 0;
}

void han() {
	int n;
	cin >> n;

	int count = 0;

	for (int i = 1; i <= n; i++) {
		if (i >= 1 && i < 100)
			count++;
		else if (i >= 100 && i < 1000) {
			if ((i % 10 - (i / 10) % 10) == ((i / 10) % 10 - i / 100))
				count++;
		}
	}

	cout << count;
}