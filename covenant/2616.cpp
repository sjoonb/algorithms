#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int accumSum[50001];
int dp[3][50001];

int dfs(int cars, int src) {
	if(cars == 0)
		return 0;
	int &ret = dp[cars-1][src];
	if(ret != -1)
		return ret;

	ret = 0;
	if(src + (M-1) <= N)
		ret = dfs(cars-1, src+M) + accumSum[src+M-1] - accumSum[src-1];
	if(src + 1 <= N)
		ret = max(ret, dfs(cars, src+1));
	return ret;
}

int main() {
	cin >> N;
	accumSum[0] = 0;
	for(int i=1; i<=N; ++i) {
		int num;
		cin >> num;
		accumSum[i] = accumSum[i-1] + num;
	}
	cin >> M;
	memset(dp, -1, sizeof(dp));
	cout << dfs(3, 1);
	return 0;
}
