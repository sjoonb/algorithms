#include <iostream>
#include <cstring>
using namespace std;

int N;
int dp[30][3];

// type
// 0 1 2 
// x x o |
// x x x v
// x o x


int dfs(int i, int type) {
	if(i >= N)
		return (i == N && type == 0) ? 1: 0;
	int &ret = dp[i][type];
	if(ret != -1)
		return ret;
	ret = dfs(i+2, type);
	switch(type) {
		case 0:
			ret += dfs(i+1, 1);
			ret += dfs(i+1, 2);
			break;
		case 1:
		case 2:
			ret += dfs(i+1, 0);
			break;
	}
	return ret;
}
int main() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
	return 0;	
}
