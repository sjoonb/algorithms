#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int P[10001];
int dp[10001][1000];

int dfs(int src, int num) {
	if(num == N)
		return 0;	
	int &ret = dp[src][num];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i=src; i<=N; ++i)
		if(num + i <= N)
			ret = max(ret, dfs(i, num+i) + P[i]); 
	return ret;		
}
	
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i=1; i<=N; ++i)
		cin >> P[i];	
	int ret = 0;
	for(int i=1; i<=N; ++i)
		ret = max(ret, dfs(i, 0));
	cout << ret;
	return 0;
}
