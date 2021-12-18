#include <iostream>
#include <vector>
using namespace std;

bool decision(const vector<double>& location, int cameras, double gap) {
	double limit = -1;
	int installed = 0;
	for(int i=0; i<location.size(); ++i) {
		if(limit <= location[i]) {
			++installed;
			limit = location[i] + gap;
		}
	}
	return installed >= cameras;
}

double optimize(const vector<double>& location, int cameras) {
	double lo=0, hi=241;
	for(int it=0; it<100; ++it) {
		double mid = (lo + hi)/2.0;
		cout << "lo: " << lo << " ";
		cout << "hi: " << hi << " ";
		cout << "mid: " << mid << " ";
		cout << "\n";
		if(decision(location, cameras, mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main() {
	cout.precision(2);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n, m;
		cin >> n >> m;
		vector<double> locations(m);
		for(int i=0; i<m; ++i) cin >> locations[i];
		cout << fixed;
		cout << optimize(locations, n) << "\n";
	}
}
