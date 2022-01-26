#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<string> colors;
vector<vector<bool> > isVisited;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) {
	if(y >= 0 && y < M && x >=0 && x < N)
		return true;
	return false;
}

int dfs(int y, int x, char color) {
	if(!inRange(y, x))
		return 0;
	if(colors[y][x] != color)
		return 0;
	if(isVisited[y][x])
		return 0;

	isVisited[y][x] = true;
	int ret = 1;
	for(int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		ret += dfs(ny, nx, color);
	}
	return ret;
}

void solve() {
	int white = 0;
	for(int i=0; i<M; ++i)
		for(int j=0; j<N; ++j)
			if(!isVisited[i][j]) {
				white += pow(dfs(i, j, 'W'), 2);
			}
	int blue = 0;
	for(int i=0; i<M; ++i)
		for(int j=0; j<N; ++j)
			if(!isVisited[i][j]) {
				blue += pow(dfs(i, j, 'B'), 2);
			}
	cout << white << " " << blue;
}

int main() {
	cin >> N >> M;
	colors = vector<string>(M);
	isVisited = vector<vector<bool > >(M, vector<bool>(N, false));
	for(int i=0; i<M; ++i)
		cin >> colors[i];
	solve();	
}
