#include <iostream>
using namespace std;

const int mod = 1e7;
int dp[101][101];

int poly(int n, int first) {
	if(n == first) return 1;
	int& ret = dp[n][first];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int second=1; second<=n-first; ++second) {
		int add = (first == 0) ? 1 : second + first - 1;
		add *= poly(n-first, second);		
		add %= mod;
		ret += add;
		ret %= mod;
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int n;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << poly(n, 0) << "\n";
	}
	return 0;
}
