#include <iostream>
#include <vector>
using namespace std;

int n, k, r[1000], c[1000];

bool decision(double x) {
	vector<double> v;
	for(int i=0; i<n; ++i)
		v.push_back(x*c[i] - r[i]);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	double sum=0;
	for(int i=0; i<k; ++i)
		sum += v[i];
	return sum >= 0;
}

double optimize() {
	double lo = -1e-9, hi=1;
	for(int iter=0; iter<100; ++iter) {
		double mid = (lo+hi)/2;
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
		for(int i=0; i<n; ++i) cin >> r[i] >> c[i];
		cout << optimize() << "\n";
	}
	return 0;	
}

