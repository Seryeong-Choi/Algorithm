#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, mid, u_bound;

void binary(long long l, long long r) {
	if (l <= r) {
		mid = (l + r) / 2;
		long long temp = 0;
		for (long long i = 1; i <= min(n,mid); i++)
			temp += min(n, mid / i);

		if (temp < k) 
			binary(mid + 1, r);

		else{ //temp >= k
			u_bound = mid;
			binary(l, mid - 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> k;
	//binarysearch
	binary(1, k);
	//output
	cout << u_bound;
}