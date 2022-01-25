#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int L;
int dp[5001];

int dfs(int num) {
	if(num <= 2)
		return 1;
	int &ret = dp[num];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i=0; i <= num-2; i+=2) {
		ret += ((dfs(i) % MOD) * (dfs(num-2-i) % MOD)) % MOD;
	}
	return ret %= MOD;
}

int main() {
	int cases;
	cin >> cases;
	memset(dp, -1, sizeof(dp));
	for(int cc=0; cc<cases; ++cc) {
		cin >> L;
		if(L % 2 == 0)
			cout << dfs(L) << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
