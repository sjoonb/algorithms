#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;
int connected[50][50], deg[50];
double dp[50][101];

double search(vector<int>& path) {
	if(path.size()-1 == d) {
		if(path.back() != q) return 0.0;
		double ret = 1.0;
		for(int i=0; i<path.size()-1; ++i) {
			ret /= deg[path[i]];
		}
		return ret;
	}
	double ret = 0;
	for(int there=0; there<n; ++there) {
		if(connected[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}

double search2(int here, int days) {
	if(days == 0) return (here == q) ? 1.0 : 0.0;
	double& ret = dp[here][days];
	if(ret != -1.0) return ret;
	ret = 0;
	for(int there=0; there<n; ++there)
		if(connected[here][there])
			ret += search2(there, days-1)/deg[here];
	return ret;
}

double search3(int here, int days) {
	if(days == 0) return (here == p) ? 1.0 : 0.0;
	double& ret = dp[here][days];
	if(ret != -1.0) return ret;
	ret = 0;
	for(int there=0; there<n; ++there)
		if(connected[here][there])
			ret += search3(there, days-1)/deg[there];
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> d >> p;
		memset(connected, 0, sizeof(connected));
		memset(deg, 0, sizeof(deg));
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j) {
				cin >> connected[i][j];
				if(connected[i][j])
					deg[i]++;
			}
		for(int i=0; i<n; ++i)
			for(int j=0; j<=d; ++j) 
				dp[i][j] = -1.0;
		int t;
		cin >> t;
		for(int i=0; i<t; ++i) {
			cin >> q;
//			vector<int> path;
//			path.push_back(p);
//			cout << search(path) << "\n";
			cout << search3(q, d) << "\n";
		}
	}
	return 0;
}
