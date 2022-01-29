#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e6;

int N;
int pw[5000];
int dp[5000];

int dfs(int i) {
	if(i == N)
		return 1;
	int &ret = dp[i];
	if(ret != -1)
		return ret;	
	ret = 0;
	if(pw[i] != 0)
		ret += dfs(i+1);
	if(i+2 <= N && pw[i] != 0 && pw[i] <= 2 && pw[i+1] <=6)
		ret = (ret + dfs(i+2)) % MOD;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	string str;
	cin >> str;
	N = str.size();
	for(int i=0; i<N; ++i)
		pw[i] = str[i] - '0';
	cout << dfs(0);
}
