#include <iostream>
#include <string>
using namespace std;

int solve();
int title(int n);
bool check(int a);
int main() {
	cout << solve();
	return 0;
}

int solve() {
	int n = 1;

	cin >> n;

	return title(n);
}

int title(int n) {
	int a = 666;
	int i = 0;

	while (i < n - 1) {
		a++;
		if (check(a))
			i++;
	}
	return a;
}

bool check(int a) {

	string check = to_string(a);

	if (check.find("666") != std::string::npos) {
		return 1;
	}
	else
		return 0;
}