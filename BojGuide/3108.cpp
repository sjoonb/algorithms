#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool board[2001][2001];
bool isVisited[2001][2001];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};


int draw(int x1, int y1, int x2, int y2) {
	for(int i=y1; i<=y2; ++i) {
		board[i][x1] = true;
		board[i][x2] = true;
	}
	for(int j=x1+1; j<x2; ++j) {
		board[y1][j] = true;
		board[y2][j] = true;
	}
	return 0;
}

bool inRange(int y, int x) {
	if(y >= 0 && y <= 2000 && x >= 0 && x <= 2000)
		return true;
	return false;
}

void dfs(int y, int x) {
	isVisited[y][x] = true;
	for(int k=0; k<4; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if(inRange(ny, nx) && !isVisited[ny][nx] && board[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;	
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;
		draw(x1, y1, x2, y2);
	}
	int ret = 0;
	for(int i=0; i<=2000; ++i)
		for(int j=0; j<=2000; ++j)
			if(!isVisited[i][j] && board[i][j]) {
				dfs(i, j);
				ret++;
			}
	if(board[1000][1000])
		ret--;
	cout << ret;
	return 0;	
}
