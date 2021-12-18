#include <iostream>
#include <cstring>
using namespace std;

int n, tri[100][100], dp[100][100], dp2[100][100];

int solve(int y, int x) {
	if(y == n-1) return dp[y][x] = tri[y][x];
	int& ret=dp[y][x];
	if(ret != -1) return ret;
	return ret = tri[y][x] + max(solve(y+1, x), solve(y+1, x+1));
}

int count(int y, int x) {
	if(y == n-1) return 1;
	int& ret = dp2[y][x];
	if(ret != -1)
		return ret;
	ret = 0;
	if(solve(y+1, x) >= solve(y+1, x+1)) ret += count(y+1, x);
	if(solve(y+1, x) <= solve(y+1, x+1)) ret += count(y+1, x+1);
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n;
		for(int i=0; i<n; ++i)
			for(int j=0; j<=i; ++j)
				cin >> tri[i][j];
		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));
		//solve(0, 0);
		cout << count(0, 0) << "\n";
	}
	return 0;
}
