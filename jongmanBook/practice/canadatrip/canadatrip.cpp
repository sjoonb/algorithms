#include <iostream>
using namespace std;

int n, k;
int l[5000], m[5000], g[5000];

int decision(int dist) {
	int ret=0;
	for(int i=0; i<n; ++i) 
	return ret >= k;
}

int optimize() {
	int lo = -1, hi = 8030001;
	while(lo+1 < hi) {
		int mid = (lo + hi)/2;
		if(decision(mid))
			hi = mid;
		else
			lo = mid;
			
	}
	return hi;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		cin >> n >> k;
		for(int i=0; i<n; ++i)
			cin >> l[i] >> m[i] >> g[i];
		cout << optimize() << "\n";
	}
	return 0;
}
