#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> pos;
typedef pair<int, char> turn;
int n, k, l, t = 0, to_index = 0, dir_index = 0, eaten_apple = 0;
bool apple[100][100]; //����� ������ true
bool flag = true; //��� �Ծ����� ����
turn to[100]; //�̵� ����
pos dir[4] = { {0,1},{1,0},{0,-1},{-1,0} }; //��, ��, ��, ��//�ð����
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
	
	snake.push_back({ 0,0 }); //������ġ
	pos temp;
	//cur_dir = dir[dir_index]; 
	while (true) {
		flag = false;
		temp.first = snake.front().first + dir[dir_index].first;
		temp.second = snake.front().second + dir[dir_index].second;
		t++;
		//���̸� ����
		if (temp.first < 0 || temp.first == n || temp.second < 0 || temp.second == n) {
			break;
		}
		//�Ӹ��� ���뿡 �ε������� ����
		if (find(snake.begin(), snake.end(), temp) != snake.end()) {
			break;
		}
		//�̵� �������� Ȯ�ε����� �Ӹ� ��ġ Ǫ
		snake.push_front(temp);
		//����Ծ����� Ȯ��
		if (apple[snake.front().first][snake.front().second]) {
			eaten_apple++;
			apple[snake.front().first][snake.front().second] = false;
			flag = true;
		}
		//��� �ȸԾ����� ���� ��ĭ �ڸ�
		if (!flag)
			snake.pop_back();
		//�̹� �� ������ ���� ��ȯ�ϴ��� Ȯ��
		if (to_index < l && to[to_index].first == t) { // L ��ȸ�� +3%4 // D ��ȸ�� +1%4
			if (to[to_index].second == 'D') 
				dir_index = (dir_index + 1) % 4;
			else 
				dir_index = (dir_index + 3) % 4;
			
			to_index++;
		}
	}

	cout << t;
}