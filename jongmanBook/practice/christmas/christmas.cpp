#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;

int n, k;
long long psum[MAX_N]; 


void partialSum(vector<int>& vec) {
	psum[0] = vec[0];
	for(int i=1; i<vec.size(); ++i)
		psum[i] = psum[i-1] + vec[i];
}

void read() {
	cin >> n >> k;
	vector<int> vec = vector<int>(n);
	for(int i=0; i<n; ++i)
		cin >> vec[i];
	partialSum(vec);
}

int solve() {
	int ret=0;
	for(int i=0; i<n-1; ++i)
		for(int j=i+1; j<n; ++j) {
			if((psum[i]-psum[j])%k == 0)
				ret = (ret+1) % 20091101;
		}
	return ret;
}

// 0 번 상자부터 i 번 상자까지의 범위 내에서 서로 겹치지 않고 구매할 수 있는 부분 구간의 최대 수

int dp[MAX_N];
int maxBuys(int i) {
	if(i<0)
		return 0;
	int& ret = dp[i];
	if(ret != -1) return ret;
	ret = maxBuys(i-1);
	for(int j=i-1; j >= 0; --j)
		if((psum[i]-psum[j])%k == 0) 
			ret = max(ret, maxBuys(j-1) + 1);
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		read();
		memset(dp, -1, sizeof(dp));
		cout << solve() <<  " " << maxBuys(n) << "\n";
	}
}

