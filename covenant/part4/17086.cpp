#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N, M;
int space[50][50];
bool isVisited[50][50];
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};


bool inRange(int y, int x) {
	if(y >= 0 && y < 50 && x >= 0 && x < 50)
		return true;
	return false;
}

int bfs(int y, int x) {
	memset(isVisited, false, sizeof(isVisited));
	queue<tuple<int, int, int>> q; // y, x, depth;
	q.push(make_tuple(y, x, 0));
	isVisited[y][x] = true;
	while(!q.empty()) {
		int cy = get<0>(q.front());	
		int cx = get<1>(q.front());	
		int depth = get<2>(q.front());	
		q.pop();
		if(space[cy][cx] == 1)
			return depth;
		for(int k=0; k<8; ++k) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];
			if(inRange(ny, nx) && !isVisited[ny][nx]) {
				isVisited[ny][nx] = true;
				q.push(make_tuple(ny, nx, depth+1));
			}
		}
	}
	return 0;
}

int solve() {
	int ret=0;
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			if(space[i][j] == 0)
				ret = max(ret, bfs(i, j));
	return ret;
}

int main() {
	cin >> N >> M;	
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			cin >> space[i][j];
	cout << solve();
}
