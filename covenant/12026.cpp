#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
int dp[1000];
int blocks[1000];

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

int solve() {
	dp[0] = 0;
	for(int i=1; i<N; ++i) 
		for(int j=i-1; j>=0; --j)
			if(blocks[j] == (blocks[i]+3-1) % 3)
				dp[i] = min(dp[i], dp[j] + (int)pow(i-j, 2));
	return dp[N-1];
}

int main() {
	cin >> N;
	string str;
	cin >> str;
	for(int i=0; i<str.size(); ++i) {
		blocks[i] = encoding(str[i]);
	}
	for(int i=0; i<N; ++i)
		dp[i] = INF;
	int ret = solve();
	if(ret == INF)
		cout << -1;
	else
		cout << ret;
}
