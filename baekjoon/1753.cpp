#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

int V, E, K;
vector<int> dist;
vector<vector<pair<int, int> > > adjList;

void dijkstra(int start) {
	priority_queue<pair<int ,int>> pq;
	pq.push({0, start});
	while(!pq.empty()) {
		int w = -pq.top().first;		
		int here = pq.top().second;
		pq.pop();
		if(dist[here] != INF)
			continue;
		dist[here] = w;
		for(int j=0; j<adjList[here].size(); ++j) {
			int there = adjList[here][j].first;
			int cost = adjList[here][j].second;
			if(dist[there] == INF)
				pq.push({-(dist[here] + cost), there});
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> V >> E >> K;
	dist = vector<int>(V+1, INF);
	adjList = vector<vector<pair<int, int> > >(V+1);
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adjList[u].push_back({v, w});
	}
	dijkstra(K);
	for(int i=1; i<=V; ++i)
		if(dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	return 0;
}
