#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long dp[101];

long long solve() {
	for(int i=1; i<=N; ++i) {
		dp[i] = dp[i-1] + 1;	
		for(int j=3; i-j>0; ++j)
			dp[i] = max(dp[i], dp[i-j]*(j-1));
	}
	return dp[N];
}

int main() {
	cin >>  N;
	cout << solve();
}
 
