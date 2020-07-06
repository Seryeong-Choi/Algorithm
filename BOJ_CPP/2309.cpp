#include <iostream>
#include <algorithm>
using namespace std;

void dwarf();
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dwarf();

	return 0;
}

void dwarf() {
	int dwarfs[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}

	sort(dwarfs, dwarfs + 9);

	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - dwarfs[i] - dwarfs[j] == 100) {
				index1 = i;
				index2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != index1 && i != index2)
			cout << dwarfs[i] << "\n";
	}
}