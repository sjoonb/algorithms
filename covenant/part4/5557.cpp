#include <iostream>
using namespace std;

int N;
int numbers[101];
long long dp[101][21];

long long solve() {
	dp[0][0] = 1;
	for(int i=1; i<N; ++i) {
		int num = numbers[i];	
		for(int j=0; j<=20; ++j) {
			if(j - num >= 0)
				dp[i][j-num] += dp[i-1][j];
			if(j + num <= 20)
				dp[i][j+num] += dp[i-1][j];
		}
	}
	return dp[N-1][numbers[N]];
}

int main() {
	cin >> N;
	for(int i=1; i<=N; ++i)
		cin >> numbers[i];
	cout << solve();
}
