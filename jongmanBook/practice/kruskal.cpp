#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DistjointSet {
	vector<int> parent, rank;
	DistjointSet(int n): parent(n), rank(n, 0) {
		for(int i=0; i<n; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if(parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int a, int b) {
		int u = find(a);
		int v = find(b);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u, v);
		if(rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};
const int MAX_V = 100;

vector<pair<int, int> > adj[MAX_V];
int V;

int kruskal(vector<pair<int, int> >& selected) {
	selected.clear();
	vector<pair<int, pair<int, int> > > edges;
	for(int u=0; u<V; ++u)
		for(int i=0; i<adj[u].size(); ++i) {
			int v = adj[u][i].first;
			int cost = adj[u][i].second;
			cout << u << " " << v << endl;
			edges.emplace_back(cost, make_pair(u, v));
		}
	sort(edges.begin(), edges.end());
	DistjointSet sets(V);
	int ret = 0;
	for(int i=0; i<edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		if(sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		selected.emplace_back(u, v);
		ret += cost;
	}
	return ret;	
}

int main() {
	int E;
	cin >> V >> E;
	for(int i=0; i<E; ++i) {
		int u, v, w;	
		cin >> u >> v >> w;
		u--; v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	vector<pair<int, int> > selected;
	cout << kruskal(selected);
	return 0;
}





