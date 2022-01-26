#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int> > maze;
vector<vector<int> > dist;
vector<vector<bool> > isVisited;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

int bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	isVisited[0][0] = true;
	dist[0][0] = 1;
	while(!q.empty()) {
		int y = q.front().first;	
		int x = q.front().second;
		q.pop();
		if(y == N-1 && x == M-1)
			break;
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i]; 	
			int nx = x + dx[i];
			if(inRange(ny, nx) && !isVisited[ny][nx] && maze[ny][nx]) {
				q.push(make_pair(ny, nx));
				isVisited[ny][nx] = true;
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}
	return dist[N-1][M-1];
}

int main() {
	cin >> N >> M;	
	maze = vector<vector<int> >(N, vector<int>(M));
	dist = vector<vector<int> >(N, vector<int>(M, 0));
	isVisited = vector<vector<bool> >(N, vector<bool>(M, false));
	for(int i=0; i<N; ++i) {
		string str;
		cin >> str;
		for(int j=0; j<str.size(); ++j) {
			maze[i][j] = str[j] - '0';	
		}
	}
	cout << bfs();
}
