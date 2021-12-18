#include <iostream>
#include <vector>
using namespace std;

int n, d, p, adj[50][50];
double ans[50], padj[50][50];

void makeProbAdj() {
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			padj[i][j] = 0.0;
	for(int i=0; i<n; ++i) {
		vector<int> path;
		for(int j=0; j<n; ++j) {
			if(adj[i][j]) {
				path.push_back(j);	
			}
		}
		double prob = 1.0/path.size();
		for(int idx: path)
			padj[i][idx] = prob;
	}
}

void dot(const double padj[][50], double* ans) {
	double result[50] = { 0,};
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			result[i] += padj[j][i] * ans[j];
		}
	}
	for(int i=0; i<n; ++i)
		ans[i] = result[i];
}

void solve() {
	makeProbAdj();	
	for(int i=0; i<50; ++i) ans[i] = 0.0;
	ans[p] = 1.0;	
	for(int i=0; i<d; ++i) {
		dot(padj, ans);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(nullptr);
	cout.precision(8);
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> d >> p;		
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j) 
				cin >> adj[i][j];
		solve();
		int t;
		cin >> t;
		for(int i=0; i<t; ++i) {
			int q;
			cin >> q;
			cout << fixed;
			cout << ans[q] << " ";
		}
	}
	return 0;
}
