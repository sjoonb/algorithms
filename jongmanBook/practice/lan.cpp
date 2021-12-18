#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


typedef pair<int, int> Pair;

vector<pair<int, double> > adj[500];

int V;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n): parent(n), rank(n, 0) {
		for(int i=0; i<n; ++i)
			parent[i] = i;
	}	
	int find(int u) {
		if(parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if(u==v) return;
		if(rank[u] > rank[v]) swap(u, v);
		if(rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};

double kruskal() {
	vector<pair<double, pair<int, int> > > edges;
	for(int u=0; u<V; ++u) {
		for(int i=0; i<adj[u].size(); ++i) {
			int v = adj[u][i].first;
			double cost = adj[u][i].second;
			edges.emplace_back(cost, make_pair(u, v));
		}
	}
	sort(edges.begin(), edges.end());
	DisjointSet buf(V);
	double ret=0;
	for(int i=0; i<edges.size(); ++i) {
		int u = edges[i].second.first;	
		int v = edges[i].second.second;	
		double cost = edges[i].first;
		if(buf.find(u) == buf.find(v)) continue;
		buf.merge(u, v);
		ret += cost;
	}
	return ret;
}

int solve() {
	int E;	
	cin >> V >> E;
	vector<Pair> coordinates(V);
	for(int i=0; i<V; ++i) cin >> coordinates[i].first;
	for(int i=0; i<V; ++i) cin >> coordinates[i].second;
	for(int i=0; i<V; ++i) adj[i].clear();
	for(int i=0; i<V; ++i)
		for(int j=0; j<i; ++j) {
			int ix = coordinates[i].first; int iy = coordinates[i].second;
			int jx = coordinates[j].first; int jy = coordinates[j].second;
			double w = sqrt(pow(ix - jx, 2) + pow(iy - jy, 2));
			adj[i].emplace_back(j, w);
		}
	for(int i=0; i<E; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, 0);
		adj[v].emplace_back(u, 0);
	}
	cout << fixed;
	cout << kruskal();
	return 0;
}

int main() {
	cout.precision(10);
	int t;
	cin >> t;
	while(t--) {
		cout << solve() << "\n";	
	}
	return 0;	
}
