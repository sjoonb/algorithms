#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

map<vector<int>, int> preSort;

void precalc(int n) {
	vector<int> origin(n);
	for(int i=0; i<n; ++i)
		origin[i] = i+1;
	queue<vector<int> > q;
	q.push(origin);
	preSort[origin] = 0;
	while(!q.empty()) {
		vector<int> here = q.front();
		q.pop();	
		int cost = preSort[here];
		for(int i=0; i<n; ++i) {
			for(int j=i+2; j<=n; ++j) {
				reverse(here.begin()+i, here.begin()+j);
				if(preSort.count(here) == 0) {
					preSort[here] = cost+1;
					q.push(here);
				}
				reverse(here.begin()+i, here.begin()+j);
			}
		}
	}
}

void solve() {
	int n;	
	cin >> n;
	vector<int> perm(n);
	for(int i=0; i<n; ++i) cin >> perm[i];
	vector<int> transformed(n);
	for(int i=0; i<n; ++i) {
		int smaller = 0;	
		for(int j=0; j<n; ++j) {
			if(perm[i] >= perm[j])
				smaller++;	
		}
		transformed[i] = smaller;
	}
	printf("%d\n", preSort[transformed]);
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=8; ++i)
		precalc(i);
	while(t--)
		solve();
	return 0;	
}
