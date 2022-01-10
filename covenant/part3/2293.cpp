#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;
int dp[100001];
vector<int> coin;

int solve() {
	dp[0] = 1;
	for(int i=0; i<coin.size(); ++i)
		for(int j=coin[i]; j<=K; j ++) {
			dp[j] += dp[j - coin[i]];
		}
	return dp[K];
}

int main() {
	cin >> N >> K;
	coin = vector<int>(N);
	for(int i=0; i<N; ++i)
		cin >> coin[i];
	cout << solve();
}

