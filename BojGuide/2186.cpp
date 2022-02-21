#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M, K;
int dp[100][100][80];
vector<string> board;
string word;


bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

int dfs(int y, int x, int index) {
	if(index == word.size()-1)
		return 1;	
	int &ret = dp[y][x][index];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int k=0; k<4; ++k) 
		for(int mul=1; mul<=K; ++mul) {
			int ny = y + dy[k] * mul;	
			int nx = x + dx[k] * mul;	
			if(inRange(ny, nx) && board[ny][nx] == word[index+1])
				ret += dfs(ny, nx, index+1);
		}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	board = vector<string>(N);
	for(int i=0; i<N; ++i)
		cin >> board[i];
	cin >> word;
	int ret = 0;
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			if(board[i][j] == word[0])
				ret += dfs(i, j, 0);
	cout << ret;
	return 0;	
}
