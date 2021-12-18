#include <iostream>
#include <vector>
using namespace std;

struct point {
	double y, x;
};

vector<point> hull1, hull2;
vector<pair<point, point> > upper, lower;

void decompose(const vector<point>& hull) {
	int n = hull.size();	
	for(int i=0; i<n; ++i) {
		if(hull[i].x < hull[(i+1)%n].x)
			lower.emplace_back(hull[i], hull[(i+1)%n]);
		else if(hull[i].x > hull[(i+1)%n].x)
			upper.emplace_back(hull[i], hull[(i+1)%n]);
	}
}

double minX(const vector<point>& hull) {
	double ret = 1e20;
	for(int i=0; i<hull.size(); ++i) ret = min(ret, hull[i].x);
	return ret;
}

double maxX(const vector<point>& hull) {
	double ret = -1e20;
	for(int i=0; i<hull.size(); ++i) ret = max(ret, hull[i].x);
	return ret;
}

bool between(const point& a, const point& b, double x) {
	return (a.x <= x && x <= b.x || b.x <= x && x <= a.x);
}

double at(const point& a, const point& b, double x) {
	double dy = b.y - a.y, dx = b.x - a.x;
	return dy/dx*(x-a.x) + a.y;
}

double vertical(double x) {
	double minUp = 1e20, maxLow = -1e20;
	for(int i=0; i<upper.size(); ++i)
		if(between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	for(int i=0; i<lower.size(); ++i)
		if(between(lower[i].first, lower[i].second, x))
			maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
	return minUp - maxLow;
}

double solve() {
	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));
	if(hi < lo) return 0;
	for(int iter=0; iter<100; ++iter) {
		double aab = (lo*2 + hi) / 3.0;	
		double abb = (lo + hi*2) / 3.0;	
		if(vertical(aab) < vertical(abb))
			lo = aab;
		else
			hi = abb;
	}
	return max(0.0, vertical(hi));
}

int main() {
	cout.precision(8);
	int cases;	
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n, m;
		cin >> n >> m;
		hull1.resize(n);
		hull2.resize(m);
		for(int i=0; i<n; ++i) cin >> hull1[i].x >> hull1[i].y;
		for(int i=0; i<m; ++i) cin >> hull2[i].x >> hull2[i].y;
		upper.clear();
		lower.clear();
		decompose(hull1);
		decompose(hull2);
		cout << fixed << solve() << "\n";
	}
}
