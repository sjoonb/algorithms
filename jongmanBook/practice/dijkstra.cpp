#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int V;
vector<pair<int, int> > adj[20001];
vector<int> dist;

void dijkstra(int src) {
	dist = vector<int>(V+1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < cost) continue;
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
}

int main() {
	int E;
	cin >> V >> E;
	int src;
	cin >> src;
	for(int i=0; i<E; ++i) {
		int u, v, w;	
		cin >> u >> v  >> w;
		adj[u].push_back(make_pair(v, w));
	}
	dijkstra(src);
	for(int i=1; i<=V; ++i) {
		if(dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << "\n";
	}
	return 0;	
}
