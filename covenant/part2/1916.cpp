#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 1;

int n, m;

vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<bool> isVisited;

int minUnvisitedVertex() {
	int minVertex = 0;
	int minDist = INF;
	for(int i=1; i<=n; ++i)
		if(!isVisited[i] && dist[i] < minDist) {
			minDist = dist[i];
			minVertex = i;	
		}
	return minVertex;
}

int dijkstra(int src, int dest) {
	dist = vector<int>(n+1, INF);
	isVisited = vector<bool>(n+1, false);
	dist[src] = 0;	
	for(int i=1; i<=n; ++i) {
		int here = minUnvisitedVertex();	
		isVisited[here] = true;

		for(int j=0; j<graph[here].size(); ++j) {
			int there = graph[here][j].first;
			int candDist = graph[here][j].second;
			if(dist[here] + candDist < dist[there])
				dist[there] = dist[here] + candDist;
		}
	}
	return dist[dest];
}

void initGraph() {
	graph = vector<vector<pair<int, int>>>(n+1);	
	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
}

int main() {
	cin >> n >> m;
	initGraph();	
	int src, dest;
	cin >> src >> dest;
	cout << dijkstra(src, dest);
	return 0;
}

