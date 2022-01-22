#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int W[101];
int V[101];
int dp[2][100001];

int solve() {
	for(int i=1; i<=N; ++i)
		for(int j=0; j<=K; ++j) {
			if(j-W[i] >= 0)
				dp[i%2][j] = max(dp[(i+1)%2][j], dp[(i+1)%2][j-W[i]] + V[i]);
			else
				dp[i%2][j] = dp[(i+1)%2][j];
		}
	return dp[N%2][K];
}

int main() {
	cin >> N >> K;	
	for(int i=1; i<=N; ++i)
		cin >> W[i] >> V[i];
	cout << solve();
}
