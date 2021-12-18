#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dp[101];
const int p = 1000000007;

int tiling(int idx) {
	if(idx == n) return 1;
	int& ret = dp[idx];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=1; i<=2; ++i) {
		if(idx+i <= n) {
			ret += tiling(idx + i);	
			ret %= p;
		}
	}
	return ret;
}

// 5 til 4 + til 3
// til 4 / til 3 + til 2
// til 3 / til 2 + til 1
// til 2 /til 1 + til 0 = 2
// til 3 / 2 + 1
// til 4 / 3 + til 2
int ans(int width) {
	if(width <= 1)
		return 1;
	int& ret = dp[width];
	if(ret != -1) return ret;
	return ret = (ans(width - 1) + ans(width - 2)) % p;	
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		//cout << tiling(0) << "\n"; 
		cout << ans(n) << "\n"; 
	}
	return 0;
}
