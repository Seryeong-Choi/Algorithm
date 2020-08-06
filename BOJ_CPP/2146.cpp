#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> map(100, vector<int>(100));
vector<vector<int>> clonemap;
vector<vector<int>> visited(100, vector<int>(100, 0));
vector<vector<int>> edge(100, vector<int>(100, 0));
int posX[4] = { 0, 0, 1, -1 };
int posY[4] = { 1, -1, 0, 0 };
queue<vector<int>> recl;
int n, island = 0; //for numbering islands

bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	else return false;
}

void dfs(int x, int y) {
	int i, j;
	for (int k = 0; k < 4; k++) {
		i = x + posX[k];
		j = y + posY[k];
		if (isValid(i, j) && map[i][j] == 0)
			edge[x][y] = island; //바다에 닿으면 edge에 저장

		else if (isValid(i, j) && map[i][j] == 1 && visited[i][j] == 0) {
			map[i][j] = island;
			visited[i][j] = 1;
			dfs(i, j);
		}
	}
}

int reclamation(int num) { //bfs
	while (!recl.empty())
		recl.pop();
	clonemap = map;//섬 별로 간척사업 저장을 위한 임시맵

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (edge[i][j] == num)
				recl.push({ i,j,0 });
	int x, y, i, j;

	while (true) {
		x = recl.front()[0];
		y = recl.front()[1];
		for (int k = 0; k < 4; k++) {
			i = x + posX[k];
			j = y + posY[k];
			if (isValid(i, j) && clonemap[i][j] != 0 && clonemap[i][j] != num)
				return recl.front()[2];

			if (isValid(i, j) && clonemap[i][j] == 0) {
				clonemap[i][j] = num;
				recl.push({ i, j, recl.front()[2] + 1 });
			}
		}
		recl.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	//numbering islands
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 1 && visited[i][j] == 0) {
				island++;
				map[i][j] = island;
				visited[i][j] = 1;
				dfs(i, j);
			}
	//land reclamation
	int bridge = n * n;
	for (int i = 1; i < island; i++)
		bridge = min(bridge, reclamation(i));

	//output
	cout << bridge;
}