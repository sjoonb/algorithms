#include <iostream>
#include <cstring>
using namespace std;

int N;
int numbers[100];
long long dp[100][21];

long long solve() {
	dp[0][numbers[0]] = 1;
	for(int i=1; i<N-1; ++i) {
		int num = numbers[i];	
		for(int j=0; j<=20; ++j) {
			if(j - num >= 0)
				dp[i][j-num] += dp[i-1][j];
			if(j + num <= 20)
				dp[i][j+num] += dp[i-1][j];
		}
	}
	return dp[N-2][numbers[N-1]];
}

long long dfs(int idx, int num) {
	if(idx == N-1)
		return (num == numbers[N-1]) ? 1 : 0;
	long long &ret = dp[idx][num];
	if(ret != -1)
		return ret;
	ret = 0;
	if(num + numbers[idx] <= 20)
		ret += dfs(idx+1, num + numbers[idx]);
	if(num - numbers[idx] >= 0)
		ret += dfs(idx+1, num - numbers[idx]);
	return ret;	
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> numbers[i];
	//cout << solve() << endl;
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, numbers[0]);
}
