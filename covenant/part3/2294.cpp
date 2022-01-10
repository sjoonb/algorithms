#include <iostream>
#include <vector>
using namespace std;

#define MAX 1e5+1

int N, K;
int dp[100001];
vector<int> coin;

int solve() {
	dp[0] = 0;
	for(int i=0; i<coin.size(); ++i)
		for(int j=coin[i]; j<=K; ++j)
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	return (dp[K] != MAX) ? dp[K] : -1;
}

int main() {
	cin >> N >> K;
	coin = vector<int>(N);
	for(int i=0; i<N; ++i)
		cin >> coin[i];
	for(int i=0; i<=K; ++i)
		dp[i] = MAX;
	cout << solve();
}

