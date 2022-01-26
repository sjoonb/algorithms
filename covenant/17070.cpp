#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define horizontal 0
#define vertical 1
#define diagonal 2 

int N;
int dp[3][16][16];
vector<vector<int> > house;

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < N)
		return true;
	return false;
}

bool canPlace(int y, int x, int dType) {
	if(dType == diagonal)
		if(house[y-1][x] || house[y][x-1])
			return false;
	if(house[y][x])
		return false;
	return true;
}

bool isArrive(int y, int x) {
	if(y == N-1 && x == N-1) 
		return true;
	return false;
}

int dfs(int y, int x, int dType) {
	if(!inRange(y, x))
		return 0;
	if(!canPlace(y, x, dType))
		return 0;
	if(isArrive(y, x))
		return 1;

	int &ret = dp[dType][y][x];
	if(ret != -1) return ret;

	ret = 0;
	if(dType != vertical)
		ret += dfs(y, x+1, horizontal);
	if(dType != horizontal)
		ret += dfs(y+1, x, vertical);
	ret += dfs(y+1, x+1, diagonal);
	return ret;
}

int solve() {
	return dfs(0, 1, horizontal);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	house = vector(N, vector<int>(N));
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			cin >> house[i][j];
	cout << solve();
}
