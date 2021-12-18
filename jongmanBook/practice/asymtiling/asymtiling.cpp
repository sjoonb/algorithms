#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101];

const int MOD = 1000000007;

int tiling(int width) {
	if(width <= 1) return 1;
	int& ret = dp[width];
	if(ret != -1) return ret;
	return ret = (tiling(width-2) + tiling(width-1)) % MOD;	
}

int asymtiling(int n) {
	int ans = (tiling(n) - tiling((n-1)/2) + MOD) % MOD;
	if(n%2==1)
		return  ans;
	else
		return (ans - tiling(n/2) + MOD) % MOD;
}

int main() { 
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int n;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << asymtiling(n) << "\n";
	}
	return 0;	
}
