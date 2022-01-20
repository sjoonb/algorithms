#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1e9 * 2
int N;
int period[1500000];
int cost[1500000];
int dp[1500000];

int dfs(int day) {
	if(day >= N) 
		return (day == N) ? 0 : -INF;
	int &ret = dp[day];
	if(ret != -1)
		return ret;
	return ret = max(dfs(day+1), dfs(day+period[day])+cost[day]);
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> period[i] >> cost[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0);
	return 0;	
}
