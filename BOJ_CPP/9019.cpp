#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

vector<char> op(10000);
vector<int> parent(10000, -1);
int d, s, l, r, target;
bool finished = false;
queue<int> q;

void solution(int n);
void print(int n) {
	char ans[10001];
	ans[10000] = '\0';
	char* ptr = ans + 9999;
	do {
		*(ptr--) = op[n];
		n = parent[n];
	} while (parent[n] != n);
	puts(ptr+1);
}

void D(int n) {
	d = n * 2 % 10000;
	if (parent[d] == -1) {
		parent[d] = n;
		op[d] = 'D';
		if (d != target)
			q.push(d);
		else {
			finished = true;
			print(d);
		}
	}
}

void S(int n) {
	if (n == 0) s = 9999;
	else s = n - 1;
	if (parent[s] == -1) {
		parent[s] = n;
		op[s] = 'S';
		if (s != target)
			q.push(s);
		else {
			finished = true;
			print(s);
		}
	}
}

void L(int n) {
	if (n >= 1000)
		l = n % 1000 * 10 + n / 1000;
	else
		l = n * 10;
	
	if (parent[l] == -1) {
		parent[l] = n;
		op[l] = 'L';
		if (l != target)
			q.push(l);
		else {
			finished = true;
			print(l);
		}
	}
}

void R(int n) {
	r = n / 10 + n % 10 * 1000;

	if (parent[r] == -1) {
		parent[r] = n;
		op[r] = 'R';
		if (r != target)
			q.push(r);
		else{
			finished = true;
			print(r);
		}
	}
}

void solution(int n) {
	//initialize everything
	fill(parent.begin(), parent.end(), -1);
	q = {};
	finished = false;
	q.push(n);
	parent[n] = n;
	//
	while(!finished){
		n = q.front();
		q.pop();
		D(n);
		S(n);
		L(n);
		R(n);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int t, init;
	cin >> t;
	for (int i = 0 ; i < t ; i++) {
		cin >> init >> target;
		solution(init);
	}
}