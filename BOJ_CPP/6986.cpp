#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> nums;
	double temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums.push_back(int(temp * 10) * 100);
	}
	sort(nums.begin(), nums.end());
	//절사 합
	int first = 0;
	for (int i = k; i < nums.size() - k; i++)
		first += nums[i];
	//보정 합
	int second = first;
	second += nums[k] * k + nums[nums.size() - k - 1] * k;
	//절사평균
	first /= (n - k * 2);
	double result = 0;
	if (int(first) % 10 >= 5)
		result = (first / 10 + 1) * 0.01;
	else
		result = (first / 10) * 0.01;
	printf("%.2f\n", result);
	//보정평균
	second /= n;
	if (int(second) % 10 >= 5)
		result = (second / 10 + 1) * 0.01;
	else
		result = (second / 10) * 0.01;
	printf("%.2f\n", result);
}