#include <iostream>
using namespace std;

const int INF = 987654321;

int n, k, m, l;

int prerequisite[12];
int classes[10]

int bitCount(int n) {
	return __builtin_popcount(n);
}

int graduate(int semester, int taken) {
	if(bitCount(taken) >= k) return 0;
	if(semester == m) return INF;
	int ret = INF;
	int canTake = (classes[semester] & ~taken);
	for(int i=0; i<n; ++i)
		if((canTake & (1 << i) && (taken & prerequisite
}

void solve() {
	cin >> n >> k >> m >> l;
	for(int i=0; i<n; ++i) {
		prerequisite[i] = 0;
		int r;
		cin >> r;
		for(int j=0; j<r; ++j) {
			int required;
			cin >> required;
			prerequisite[i] |= (1 << required);
		}
	}
	for(int i=0; i<m; ++i) {
		classes[i] = 0;	
		int c;
		cin >> c;
		for(int j=0; j<c; ++j) {
			int open;
			cin >> open;
			classes[i] |= (1 << open);
		}
	}
	int ret = graduate(0, 0);
	if(ret >= INF)
		cout << "IMPOSSIBLE";
	else
		cout << ret;

}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}
