#include <iostream>
#include <cstring>
using namespace std;

int N;
int dp[2][90];

int dfs(int num, int depth) {
	if(depth == N-1)
		return 1;
	int ret = dp[num][depth];
	if(ret != -1)
		return ret;
	ret = 0;
	ret += dfs(0, depth+1);
	if(num != 1)
		ret += dfs(1, depth+1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;	
	cout << dfs(1, 0);
}
