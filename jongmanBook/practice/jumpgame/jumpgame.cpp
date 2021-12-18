#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int> > board;
int dp[100][100];
int n;

bool inRange(int y, int x) {
	return 0<=y && y<n && 0<=x && x<n;
}

int jump(int y, int x) {
	if(board[y][x] == 0) return 1;
	int dist = board[y][x];
	int ny = y+dist, nx = x+dist;
	int& ret = dp[y][x];
	if(ret != -1) return ret;
	if(inRange(ny, x))
		if(jump(ny, x))
			return 1;
	if(inRange(y, nx))
		if(jump(y, nx))
			return 1;
	return ret = 0;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n;
		board.resize(n);
		for(int i=0; i<n; ++i)
			board[i].resize(n);
		//board.resize(n, vector<int>(n, 0));
		//board = vector<vector<int> >(n, vector<int>(n, 0));
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cin >> board[i][j];
		memset(dp, -1, sizeof(dp));
		if(jump(0, 0))
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}
	return 0;	
}
