#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<vector<int> > board;
vector<vector<bool> > isVisited;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

int dfs(int y, int x) {
	if(isVisited[y][x])
		return 0;
	
	isVisited[y][x] = true;
	int ret = 1;
	for(int k=0; k<4; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if(inRange(ny, nx) && board[ny][nx]) {
			ret += dfs(ny, nx);
		}
	}
	return ret;
}

int solve() {
	int ret = 0;	
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j) {
			if(board[i][j])
				ret = max(ret, dfs(i, j));
		}
		
	return ret;
}

int main() {
	cin >> N >> M >> K;
	board = vector<vector<int> >(N, vector<int>(M, 0));
	isVisited = vector<vector<bool> >(N, vector<bool>(M, false));
	for(int i=0; i<K; ++i) {
		int y, x;
		cin >> y >> x;
		board[y-1][x-1] = 1;
	}
	cout << solve();
}
