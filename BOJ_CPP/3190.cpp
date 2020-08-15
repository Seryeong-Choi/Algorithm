#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> pos;
typedef pair<int, char> turn;
int n, k, l, t = 0, to_index = 0, dir_index = 0, eaten_apple = 0;
bool apple[100][100]; //사과가 있으면 true
bool flag = true; //사과 먹었는지 여부
turn to[100]; //이동 정보
pos dir[4] = { {0,1},{1,0},{0,-1},{-1,0} }; //동, 남, 서, 북//시계방향
//pos cur_dir;
deque<pos> snake;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> k;
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		apple[x-1][y-1] = true;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
		cin >> to[i].first >> to[i].second;
	
	snake.push_back({ 0,0 }); //시작위치
	pos temp;
	//cur_dir = dir[dir_index]; 
	while (true) {
		flag = false;
		temp.first = snake.front().first + dir[dir_index].first;
		temp.second = snake.front().second + dir[dir_index].second;
		t++;
		//벽이면 종료
		if (temp.first < 0 || temp.first == n || temp.second < 0 || temp.second == n) {
			break;
		}
		//머리가 몸통에 부딪혔으면 종료
		if (find(snake.begin(), snake.end(), temp) != snake.end()) {
			break;
		}
		//이동 가능한지 확인됐으니 머리 위치 푸
		snake.push_front(temp);
		//사과먹었는지 확인
		if (apple[snake.front().first][snake.front().second]) {
			eaten_apple++;
			apple[snake.front().first][snake.front().second] = false;
			flag = true;
		}
		//사과 안먹었으면 꼬리 한칸 자름
		if (!flag)
			snake.pop_back();
		//이번 초 끝나고 방향 전환하는지 확인
		if (to_index < l && to[to_index].first == t) { // L 좌회전 +3%4 // D 우회전 +1%4
			if (to[to_index].second == 'D') 
				dir_index = (dir_index + 1) % 4;
			else 
				dir_index = (dir_index + 3) % 4;
			
			to_index++;
		}
	}

	cout << t;
}