#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<pair<int,int> > > Graph;
typedef pair<int, pair<int, int> > Edge;
int V, E;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
Graph graph;
vector<int> parent;

int find(int x) {
	if(parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
	parent[a] = b;
}

int kruskal() {
	int ret = 0;
	int nEdge = 0;
	while(!pq.empty() && nEdge < V-1) {
		int w = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		int a = find(u);
		int b = find(v);
		if(a == b)
			continue;
		_union(a, b);
		ret += w;
		nEdge++;
	}
	return ret;
}

int main() {
	cin >> V >> E;
	graph = Graph(V+1);
	parent = vector<int>(V+1);
	for(int i=1; i<=V; ++i)
		parent[i] = i;
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
		pq.push({w, {u, v}});
	}
	cout << kruskal();
	return 0;
}
