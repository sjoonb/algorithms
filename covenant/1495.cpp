#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, S, M;
int V[50];
int dp[50][1001];

int dfs(int idx, int volume) {
	if(idx == N)
		return volume;
	int &ret = dp[idx][volume];
	if(ret != -2)
		return ret;
	ret = -1;
	if(volume + V[idx] <= M)
		ret = max(ret, dfs(idx+1, volume + V[idx]));
	if(volume - V[idx] >= 0)
		ret = max(ret, dfs(idx+1, volume - V[idx]));
	return ret;
}

int main() {
	for(int i=0; i<50; ++i)
		for(int j=0; j<1001; ++j)
			dp[i][j] = -2;
	cin >> N >> S >> M;	
	for(int i=0; i<N; ++i)
		cin >> V[i];
	cout << dfs(0, S);
}
