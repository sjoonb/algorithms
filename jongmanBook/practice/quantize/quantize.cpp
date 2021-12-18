#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
vector<int> seq;
int A[100], pSum[100], pSqSum[100];
int n, s, dp[100][11];

void precalc() {
	sort(A, A+n);
	pSum[0] = A[0];
	pSqSum[0] = A[0]*A[0];
	for(int i=0; i<n; ++i) {
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
	}
}

int minError(int lo, int hi) {
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
	int m = int(0.5 + (double)sum/(hi-lo+1));
	int ret = sqSum -2*m*sum + m*m*(hi-lo+1);
	return ret;
}

int stupidMinError(int lo, int hi) {
	int minError = INF;
	for(int i=A[lo]; i<=A[hi]; ++i) {
		int sum = 0;
		for(int j=lo; j<=hi; ++j) {
			sum += pow((A[j] - i),2);
		}
		minError = min(minError, sum);
	}
	return minError;
}

int quantize(int from, int parts) {
	if(from == n) return 0;
	if(parts == 0) return INF;
	int& ret = dp[from][parts];
	if(ret != -1) return ret;
	ret = INF;
	for(int partSize=1; from+partSize <= n; ++partSize)
		ret = min(ret, quantize(from+partSize, parts-1) + minError(from, from + partSize - 1));
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> s;
		for(int i=0; i<n; ++i) cin >> A[i];
		precalc();
		cout << quantize(0, s) << "\n";
	}
	return 0;
}
