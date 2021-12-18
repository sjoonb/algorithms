#include <iostream>
#include <random>
using namespace std;

int n, m;
double dp[201][100], places[200];

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
		if(decision(location, cameras, mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

double search3(int start, int nCamera, double minDist) {
	if(nCamera == n) {
		return minDist;
	}
	double& ret = dp[start+1][nCamera];
	if(ret != -1.0) return ret;
	ret = 0;
	for(int next=start+1; next<m; ++next) {
		double nextMinDist = (start == -1) ? minDist : min(minDist, places[next] - places[start]);
		ret = max(ret, search3(next, nCamera+1, nextMinDist));
	}
	return ret;	
}

int main() {
	cout.precision(100);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(2, 200);
	while(true) {
		m = dis(gen);
		uniform_int_distribution<int> dis2(2, m);
		n = dis2(gen);
		vector<double> locations(m);	
		cout << "m: " << m << " n: " << n << "\n";
		for(int i=0; i<m; ++i) {
			locations[i] = i+1;		
			places[i] = i+1;
			cout << i+1 << " ";
		}
		for(int i=0; i<201; ++i)
			for(int j=0; j<100; ++j)
				dp[i][j] = -1.0;
		double a = search3(-1, 0, 241);
		double b = optimize(locations, n);
		a = round(a*100)/100;
		b = round(b*100)/100;
		cout << "\n";
		cout << a << " " << b << "\n";
		assert(a == b);
	}
}
