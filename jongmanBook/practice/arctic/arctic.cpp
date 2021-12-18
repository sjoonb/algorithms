#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_V = 100;
const int INF = 1e9;

int n;
vector<pair<int, double> > adj[MAX_V];

void makeGraph(const vector<pair<double, double> >& coordinates) {
	for(int i=0; i<coordinates.size(); ++i) {
		double cy = coordinates[i].first;
		double cx = coordinates[i].second;
		for(int j=i+1; j<coordinates.size(); ++j) {
			double ny = coordinates[j].first;	
			double nx = coordinates[j].second;	
			double dist = sqrt(pow(cy-ny, 2) + pow(cx-nx, 2));
			dist = round(dist * 100)/100;
			adj[i].emplace_back(j, dist);
			adj[j].emplace_back(i, dist);
		}
	}
}

double prim() {
	vector<bool> added(n, false);	
	vector<double> minWeight(n, INF);
	double ret=0;
	minWeight[0] = 0;
	for(int iter=0; iter<n; ++iter) {
		int u=-1;
		for(int v=0; v<n; ++v)
			if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		ret = max(ret, minWeight[u]);
		added[u] = true;
		for(int i=0; i<adj[u].size(); ++i) {
			int v = adj[u][i].first;
			double weight = adj[u][i].second;
			if(!added[v] && weight < minWeight[v])
				minWeight[v] = weight;
		}
	}
	return ret;	
}

void read() {
	cin >> n;
	vector<pair<double, double> > coordinates;
	for(int i=0; i<n; ++i) {
		double y, x;
		cin >> y >> x;
		coordinates.emplace_back(y, x);
	}
	makeGraph(coordinates);
}

void clear() {
	for(int i=0; i<MAX_V; ++i)
		adj[i].clear();
}

int main() {
	cout.precision(2);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		read();
		cout << fixed;
		cout << prim() << "\n";
		clear();
	}
}
