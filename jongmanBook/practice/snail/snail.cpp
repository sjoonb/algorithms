#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
double dp[2000][1000];

double snail(int climbed, int days) {
	if(days == m) return (climbed >= n) ? 1 : 0;
	double& ret = dp[climbed][days];
	if(ret != -1.0) return ret;
	return ret = 0.75 * (snail(climbed+2, days+1)) + 0.25 * (snail(climbed+1, days+1));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(nullptr);
	cout.precision(7);
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> m;	
		for(int i=0; i<2000; ++i)
			for(int j=0; j<1000; ++j)
				dp[i][j] = -1.0;
		cout << fixed;
		cout << snail(0, 0) << "\n";
	}
	return 0;	
}
