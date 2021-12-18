#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int costSum[1001];

double solve() {
	double ret = 1e9;
	for(int i=0; i<=N-L; ++i)
		for(int j=i+L; j<=N; ++j)
			ret = min(ret, (double)(costSum[j] - costSum[i]) / (j-i));
	return ret;	
	// 1~3 cost[3] - cost[0] ... 998 ~ 1000 cost[1000] - cost [997]
	// N = 1000, j <= 1000, i <= 1000 - L, j-i 이상 없음 
}

int main() {
	cout.precision(10);
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> N >> L;
		for(int i=1; i<=N; ++i) {
		   	cin >> costSum[i];
			costSum[i] += costSum[i-1];
		}
		cout << fixed;
		cout << solve() << "\n";
	}
	return 0;	
}
