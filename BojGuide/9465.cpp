#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int board[2][100000];
int dp[3][100000];

int dfs(int type, int cols) {
	if(cols == N)
		return 0;
	int &ret = dp[type][cols];
	if(ret != -1)
		return ret;
	ret = 0;
	if(type == 0) {
		ret = max(ret, dfs(1, cols+1) + board[type][cols]);
		ret = max(ret, dfs(2, cols+1) + board[type][cols]);
	} else if(type == 1) {
		ret = max(ret, dfs(2, cols+1) + board[type][cols]);
		ret = max(ret, dfs(0, cols+1) + board[type][cols]);
	} else {
		for(int nextType=0; nextType<3; ++nextType)
			ret = max(ret, dfs(nextType, cols+1));
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for(int i=0; i<2; ++i)
			for(int j=0; j<N; ++j)
				cin >> board[i][j];
		int ret = 0;
		for(int type=0; type<3; ++type)
			ret = max(ret, dfs(type, 0));
		cout << ret << endl;
	}

	return 0;	
}

