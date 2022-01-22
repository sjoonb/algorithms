#include <iostream>
using namespace std;

int N;
int numbers[100];
long long dp[100][21];

long long solve() {
	dp[0][numbers[0]] = 1;
	for(int i=1; i<N-1; ++i) {
		int num = numbers[i];	
		for(int j=0; j<=20; ++j) {
			if(j - num >= 0)
				dp[i][j-num] += dp[i-1][j];
			if(j + num <= 20)
				dp[i][j+num] += dp[i-1][j];
		}
	}
	return dp[N-2][numbers[N-1]];
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> numbers[i];
	cout << solve();
}
