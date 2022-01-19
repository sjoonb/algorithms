#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int schedules[1500000];
int paid[1500000];
int dp[1500000];

int dfs(int day, int sum) {
	if(day >= N)
		return (day == N) ? sum : 0;
	int &ret = dp[day];
	if(ret != -1)
		return ret;
	int period = schedules[day];
	int cost =  paid[day];
	ret = dfs(day+period, sum+cost);
	if(period > 1)
		ret = max(ret, dfs(day+1, sum));
	return ret;
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> schedules[i];
		cin >> paid[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
	return 0;	
}
