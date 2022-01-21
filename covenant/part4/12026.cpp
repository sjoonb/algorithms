#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
int dp[1000];
int blocks[1000];

int dfs(int idx, int order) {
	if(idx == N-1)	
		return 0;
	int &ret = dp[idx];
	if(ret != -1)
		return ret;
	ret = INF;
	for(int next=idx+1; next<N; ++next) {
		if((order+1) % 3 == blocks[next])
			ret = min(ret, dfs(next, (order+1) % 3) + (int)pow(next-idx, 2));
	}
	return ret;
}

int encoding(char ch) {
	switch(ch) {
		case 'B':
			return 0;
		case 'O':
			return 1;
		case 'J':
			return 2;
	}
	return -1;
}

int main() {
	cin >> N;
	string str;
	cin >> str;
	for(int i=0; i<str.size(); ++i) {
		blocks[i] = encoding(str[i]);
	}
	memset(dp, -1, sizeof(dp));
	int ret = dfs(0, 0);
	(ret == INF) ? cout << -1 : cout << ret;
	return 0;	
}
