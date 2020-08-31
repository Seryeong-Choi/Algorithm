#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int ans = dist.size() + 1;
	sort(dist.begin(), dist.end());
	int weak_size = weak.size();
	for (int i = 0; i < weak_size; i++)
		weak.push_back(weak[i] + n);

	do {
		for (int i = 0; i < weak_size; i++) {
			int dist_index = 0;
			int cur = weak[i] + dist[0];
			for (int j = i + 1; j < i + weak_size; j++) {
				if (dist_index + 1 == ans)
					break;

				else if (cur >= weak[j])
					continue;
				else
					cur = weak[j] + dist[++dist_index];
			}
			ans = min(dist_index + 1, ans);
		}
	} while (next_permutation(dist.begin(), dist.end()));

	if (ans == dist.size() + 1)
		return -1;
	else
		return ans;
}