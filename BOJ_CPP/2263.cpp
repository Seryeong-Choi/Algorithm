#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> inorder, postorder; //data
vector<int> in_index;

void pre(int instart, int inend, int poststart, int postend) {
	if (instart <= inend && poststart <= postend) {
		cout << postorder[postend] << ' ';
		int root_index = in_index[postorder[postend]];
		int size = root_index - instart;

		pre(instart, root_index-1, poststart, poststart + size - 1); //left child
		pre(root_index+1, inend, poststart + size, postend - 1);//right child
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	inorder.assign(n,0);
	postorder.assign(n,0);
	in_index.assign(n + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		in_index[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	
	int root = postorder[n - 1];
	pre(0, n-1, 0, n-1);
}
/*
15
8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
8 9 4 10 11 5 2 12 13 6 14 15 7 3 1

ans
1 2 4 8 9 5 10 11 3 6 12 13 7 14 15
*/