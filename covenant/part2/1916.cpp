#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 1;

int N, M;

vector<int> dist;

// for bellman_ford
vector<pair<int, pair<int, int> > > edgeList;

// for dijkstra
vector<vector<pair<int, int> > > graph;
vector<bool> isVisited;
priority_queue<pair<int, int> > pq;

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
	} else {
		initEdgeList();
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
	} else {
		cout << bellman_ford(src, dest);
	}
	return 0;
}

