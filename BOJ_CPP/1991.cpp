#include <iostream>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
};
int n;
TreeNode* tree[26];

void preorder(TreeNode* t) {
	cout << t->data;
	if (t->left != NULL)
		preorder(t->left);
	if (t->right != NULL)
		preorder(t->right);
}

void inorder(TreeNode* t) {
	if (t->left != NULL) {
		inorder(t->left);
	}
	cout << t->data;
	if (t->right != NULL)
		inorder(t->right);
}

void postorder(TreeNode* t) {
	if (t->left != NULL)
		postorder(t->left);
	if (t->right != NULL)
		postorder(t->right);
	cout << t->data;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	char left, right, data;
	int l, r, d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode* t = new TreeNode();
		t->data = (char)(i + 'A');
		tree[i] = t;
	}

	for (int i = 0; i < n; i++) {
		cin >> data >> left >> right;
		d = data - 'A';
		l = left - 'A';
		r = right - 'A';
		if (l != '.' - 'A')
			tree[d]->left = tree[l];
		if (r != '.' - 'A')
			tree[d]->right = tree[r];
	}
	preorder(tree[0]);
	cout << endl;
	inorder(tree[0]);
	cout << endl;
	postorder(tree[0]);
}