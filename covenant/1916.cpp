#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 1;

int N, M;

vector<int> dist;

// for floyd_warshall
vector<vector<int> > adjc;

// for bellman_ford
vector<pair<int, pair<int, int> > > edgeList;

// for dijkstra
vector<vector<pair<int, int> > > graph;
vector<bool> isVisited;
priority_queue<pair<int, int> > pq;

int floyd_warshall(int src, int dest) {
	for(int k=1; k<=N; ++k)
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j) {
				adjc[i][j] = min(adjc[i][j], adjc[i][k] + adjc[k][j]);
			}
	return adjc[src][dest];
}

int bellman_ford(int src, int dest) {
	dist = vector<int>(N+1, INF);	
	dist[src] = 0;
	for(int i=0; i<N-1; ++i) {
		for(int j=0; j<M; ++j) {
			int u = edgeList[j].second.first;
			int v = edgeList[j].second.second;
			int w = edgeList[j].first;
			if(dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}
	return dist[dest];
}

int dijkstra(int src, int dest) {
	dist = vector<int>(N+1, INF);
	isVisited = vector<bool>(N+1, false);
	dist[src] = 0;	
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int here = pq.top().second;
        int currDist = -pq.top().first;
        pq.pop();
        if(dist[here] < currDist)
            continue;
		for(int j=0; j<graph[here].size(); ++j) {
			int there = graph[here][j].first;
			int candDist = graph[here][j].second;
			if(dist[here] + candDist < dist[there]) {
				dist[there] = dist[here] + candDist;
                pq.push(make_pair(-dist[there], there));
            }
		}
    }
	return dist[dest];
}

void initAdjc() {
	adjc = vector<vector<int> >(N+1, vector<int>(N+1, INF));	
	for(int i=1; i<=N; ++i)
		adjc[i][i] = 0;
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adjc[u][v] = min(adjc[u][v], w);
	}
}

void initEdgeList() {
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edgeList.push_back(make_pair(w, make_pair(u, v)));
	}
}

void initGraph() {
	graph = vector<vector<pair<int, int> > >(N+1);	
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
}

void initInputFor(string algo) {
	if(algo == "dijkstra") {
		initGraph();
	} else if(algo == "bellman_ford") {
		initEdgeList();
	} else {
		initAdjc();
	}
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
	cin.tie(0);

	string algo = argv[argc-1];
	cin >> N >> M;
	initInputFor(algo);
	int src, dest;
	cin >> src >> dest;
	
	if(algo == "dijkstra") {
		cout << dijkstra(src, dest);
	} else if(algo == "bellman_ford") {
		cout << bellman_ford(src, dest);
	} else {
		cout << floyd_warshall(src, dest);
	}
	return 0;
}

