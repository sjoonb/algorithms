#include <iostream>
#include <cstring>
using namespace std;

int N;
int board[100][100];
long long dp[100][100];

const int dy[2] = {0, 1};
const int dx[2] = {1, 0};

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < N)
		return true;
	return false;
}

long long dfs(int y, int x) {
	if(y == N-1 && x == N-1)
		return 1;
	long long &ret = dp[y][x];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int k=0; k<2; ++k) {
		int ny = y + dy[k] * board[y][x];	
		int nx = x + dx[k] * board[y][x];
		if(inRange(ny, nx))
			ret += dfs(ny, nx);
	}
	return ret;
}

int main() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j) 
			cin >> board[i][j];
	cout << dfs(0, 0);
}
