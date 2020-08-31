#include <string>
#include <vector>
#include <queue>
using namespace std;

struct robot {
	int x1, y1;
	int x2, y2;
	int time;
};
int n;
bool visited[102][102][102][102];

int solution(vector<vector<int>> board) {
	n = board.size();
	vector<pair<int, int>> pos = { {0,1},{1,0},{0,-1},{-1,0} };
	vector<vector<int>> n_board(n + 2, vector<int>(n + 2, 1));

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			n_board[i][j] = board[i - 1][j - 1];

	robot r = { 1,1,1,2,0 };
	visited[1][1][1][2] = true;
	//bfs
	queue<robot> q;
	robot front, next;
	q.push(r);
	while (!q.empty()) {
		front = q.front();
		if ((front.x1 == n && front.y1 == n) || (front.x2 == n && front.y2 == n))
			return front.time;
		q.pop();
		//cout << front.x1 << ' ' << front.y1 << ' ' << front.x2 << ' ' << front.y2 << endl;
		int temp;
		if (front.y2 < front.y1) {
			temp = front.y1;
			front.y1 = front.y2;
			front.y2 = temp;
		}
		else if (front.x2 < front.x1) {
			temp = front.x1;
			front.x1 = front.x2;
			front.x2 = temp;
		}
		//move
		for (int i = 0; i < 4; i++) {
			next.x1 = front.x1 + pos[i].first;
			next.y1 = front.y1 + pos[i].second;
			next.x2 = front.x2 + pos[i].first;
			next.y2 = front.y2 + pos[i].second;
			next.time = front.time + 1;
			if (n_board[next.x1][next.y1] == 0 && n_board[next.x2][next.y2] == 0 && !visited[next.x1][next.y1][next.x2][next.y2]) {
				q.push(next);
				visited[next.x1][next.y1][next.x2][next.y2] = true;
			}
		}
		//rotate
		if (front.x1 == front.x2) {
			if (n_board[front.x1 - 1][front.y1] == 0 && n_board[front.x2 - 1][front.y2] == 0) {
				if (!visited[front.x1 - 1][front.y1][front.x1][front.y1])
					q.push({ front.x1 - 1, front.y1, front.x1, front.y1, front.time + 1 });
				if (!visited[front.x2 - 1][front.y2][front.x2][front.y2])
					q.push({ front.x2 - 1, front.y2, front.x2, front.y2, front.time + 1 });
			}
			if (n_board[front.x1 + 1][front.y1] == 0 && n_board[front.x2 + 1][front.y2] == 0) {
				if (!visited[front.x1][front.y1][front.x1 + 1][front.y1])
					q.push({ front.x1, front.y1, front.x1 + 1, front.y1, front.time + 1 });
				if (!visited[front.x2][front.y2][front.x2 + 1][front.y2])
					q.push({ front.x2, front.y2, front.x2 + 1, front.y2, front.time + 1 });
			}
		}
		else {
			if (n_board[front.x1][front.y1 - 1] == 0 && n_board[front.x2][front.y2 - 1] == 0) {
				if (!visited[front.x1][front.y1 - 1][front.x1][front.y1])
					q.push({ front.x1, front.y1 - 1, front.x1, front.y1, front.time + 1 });
				if (!visited[front.x2][front.y2 - 1][front.x2][front.y2])
					q.push({ front.x2, front.y2 - 1, front.x2, front.y2, front.time + 1 });
			}
			if (n_board[front.x1][front.y1 + 1] == 0 && n_board[front.x2][front.y2 + 1] == 0) {
				if (!visited[front.x1][front.y1][front.x1][front.y1 + 1])
					q.push({ front.x1, front.y1, front.x1, front.y1 + 1, front.time + 1 });
				if (!visited[front.x2][front.y2][front.x2][front.y2 + 1])
					q.push({ front.x2, front.y2, front.x2, front.y2 + 1, front.time + 1 });
			}
		}
	}
}