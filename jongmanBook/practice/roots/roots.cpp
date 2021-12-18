#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> differentiate(const vector<double>& poly) {
	int n = poly.size()-1;
	vector<double> q(n);
	for(int i=1; i<=n; ++i)
		q[i-1] = i*poly[i];
	return q;
}

vector<double> solveNaive(const vector<double>& poly) {
	int n = poly.size()-1;	
	if(n==1) {
		double a = poly[1], b = poly[0];
		if(fabs(a) < 1e-8) return vector<double>();
		return vector<double>(1, -b/a);	
	} else {
		double a = poly[2], b = poly[1], c = poly[0];
		double d = b*b - 4*a*c;
		vector<double> ret;
		if(d >= 0) {
			double sqrtd = sqrt(d);
			ret.push_back((-b - sqrtd) / (2*a));
			if(sqrtd > 1e-8)
				ret.push_back((-b + sqrtd) / (2*a));
		}
		return ret;
	}
}

const double L = 25;

double evaluate(const vector<double>& poly, double x) {
	int n = poly.size() - 1;
	double ret = 0;
	for(int i=0; i<=n; ++i)
		ret += poly[i] * pow(x, i);
	return ret;
}

vector<double> solve(const vector<double>& poly) {
	int n = poly.size() - 1;
	if(n <=2 ) return solveNaive(poly);
	
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);

	sols.insert(sols.begin(), -L-1);
	sols.insert(sols.end(), L+1);
	vector<double> ret;
	for(int i=0; i<sols.size()-1; ++i) {
		double x1 = sols[i], x2 = sols[i+1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		if(y1 * y2 > 0) continue;
		if(y1 > y2) { swap(y1, y2); swap(x1, x2); }
		for(int iter=0; iter<100; ++iter) {
			double mx = (x1+x2) / 2;
			double my = evaluate(poly, mx);
			if(y1 * my > 0) {
				y1 = my;
				x1 = mx;
			} else {
				y2 = my;
				x2 = mx;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main() {
	cout.precision(9);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n;
		cin >> n;
		vector<double> coef(n+1);
		for(int i=0; i<n+1; ++i)
			cin >> coef[n-i];
		vector<double> sols = solve(coef);
		for(int i=0; i<sols.size(); ++i)
			cout << fixed << sols[i] << " ";
		cout << "\n";
	}
	return 0;	
}
