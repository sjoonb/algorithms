#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll dp[5001];

ll sol(int length) {
	if(length <= 2)
		return 1;
	ll &ret = dp[length];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i=0; i<length; i+=2) {
		ret += sol(i) * sol(length - (i + 2)) % MOD;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		memset(dp, -1, sizeof(dp));
		int L;
		cin >> L;
		if(L%2 == 1)
			cout << 0;
		else
			cout << sol(L);
		cout << "\n";
	}
	return 0;
}
