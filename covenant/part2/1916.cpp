#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 1;

int n, m;

vector<vector<pair<int, int> > > graph;
vector<int> dist;
vector<bool> isVisited;
priority_queue<pair<int, int> > pq;

int dijkstra(int src, int dest) {
	dist = vector<int>(n+1, INF);
	isVisited = vector<bool>(n+1, false);
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

void initGraph() {
	graph = vector<vector<pair<int, int> > >(n+1);	
	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	initGraph();	
	int src, dest;
	cin >> src >> dest;
	cout << dijkstra(src, dest);
	return 0;
}

