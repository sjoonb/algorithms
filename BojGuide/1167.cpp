#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
typedef vector<vector<pair<int, int> > > Graph;
Graph graph;
vector<bool> isVisited;
vector<int> dist;

void dfs(int here) {
	isVisited[here] = true;
	for(int i=0; i<graph[here].size(); ++i) {
		int there = graph[here][i].first;
		int cost = graph[here][i].second;
		if(!isVisited[there]) {
			dist[there] = dist[here] + cost;
			dfs(there);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> V;
	graph = Graph(V+1);
	isVisited = vector<bool>(V+1, false);
	dist = vector<int>(V+1, 0);
	for(int i=0; i<V; ++i) {
		int u, v, w;
		cin >> u;
		v = 0;
		cin >> v;
		while(v != -1) {
			cin >> w;
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
			cin >> v;
		}
	}
	dfs(graph[1][0].first);
	int node = -1, maxVal = 0;
	for(int i=1; i<=V; ++i) {
		if(dist[i] >= maxVal) {
			node = i;
			maxVal = dist[i];
		}
	}
	isVisited = vector<bool>(V+1, false);
	dist = vector<int>(V+1, 0);
	dfs(node);
	int ret = 0;
	for(int i=1; i<=V; ++i)
		ret = max(ret, dist[i]);
	cout << ret;
	return 0;

}





