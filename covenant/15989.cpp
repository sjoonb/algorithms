#include <iostream>
#include <cstring>
using namespace std;

int N;
int dp[3][10000];
const int coin[3] = {1, 2, 3};

int dfs(int idx, int sum) {
	if(sum == N)
		return 1;
	int &ret = dp[idx][sum];
	if(ret != -1)
		return ret;
	ret = 0;
	if(idx + 1 < 3)
		ret += dfs(idx + 1, sum);
	if(sum + coin[idx] <= N)
		ret += dfs(idx, sum + coin[idx]);
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		cout << dfs(0, 0) << endl;
	}
	return 0;
}
