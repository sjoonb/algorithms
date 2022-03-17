#include <iostream>
#include <queue>
using namespace std;

#define INF (1<<30)
typedef vector<vector<pair<int, int> > > Graph;
int V, E, K;
Graph graph;
vector<int> dist;
vector<bool> isVisited;

void dijkstra(int src) {
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, src});
	while(!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		if(isVisited[here])
			continue;
		isVisited[here] = true;
		for(int i=0; i<graph[here].size(); ++i) {
			int there = graph[here][i].first;
			int cost = graph[here][i].second;
			if(dist[there] > dist[here] + cost) {
				dist[there] = dist[here] + cost;
				pq.push({-dist[there], there});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> V >> E >> K;
	graph = Graph(V+1);
	dist = vector<int>(V+1, INF);
	isVisited = vector<bool>(V+1, false);
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
	dijkstra(K);
	for(int i=1; i<=V; ++i)
		if(dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	return 0;
}
