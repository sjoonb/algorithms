#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 1e9

int N, M;
int nameLength[1000];
int dp[1000][1001];

int dfs(int i, int lineSum) {
	if(i == N)
		return 0;
	int &ret = dp[i][lineSum];
	if(ret != -1)
		return ret;
	ret = INF;
	if(lineSum + 1 + nameLength[i] <= M)
		ret = dfs(i+1, lineSum + 1 + nameLength[i]);
	ret = min(ret, dfs(i+1, nameLength[i]) + (int)pow((M - lineSum), 2));
	return ret;
}

int main() {
	cin >> N >> M;	
	for(int i=0; i<N; ++i)
		cin >> nameLength[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, nameLength[0]);
}
