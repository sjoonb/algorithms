#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
	int w, u, v;	
};

struct Compare {
	bool operator()(Edge &a, Edge &b) {
		return a.w > b.w;
	}
};


int V, E;
priority_queue<Edge, vector<Edge>, Compare> pq;
vector<int> parent;

int find(int x) {
	if(parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);	
}

void _union(int x, int y) {
	parent[x] = y;
}

int kruskal() {
	int ret = 0;
	int nNode = 0;
	while(!pq.empty() && nNode < V-1) {
		Edge edge = pq.top();
		pq.pop();
		int a = find(edge.u);
		int b = find(edge.v);
		if(a != b) {
			_union(a, b);	
			nNode++;
			ret += edge.w;
		}
	}
	return ret;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> V >> E;
	parent = vector<int>(V+1);
	for(int i=1; i<=V; ++i)
		parent[i] = i;
	for(int i=0; i<E; ++i) {
		int u, v, w;	
		cin >> u >> v >> w;
		pq.push({w, u, v});
	}
	cout << kruskal();
	return 0;
}
