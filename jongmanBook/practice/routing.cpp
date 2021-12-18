#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <float.h>
using namespace std;


const double INF = DBL_MAX;

int n, m;
vector<pair<int, double> > adj[10000];
vector<double> dist;

void dijkstra(int src) {
	dist = vector<double>(n, INF);
	priority_queue<pair<double, int> > pq;		
	dist[src] = 1.0;
	pq.push(make_pair(-1.0, src));
	while(!pq.empty()) {
		int here = pq.top().second;	
		double cost = -pq.top().first;	
		pq.pop();
		if(cost > dist[here]) 
			continue;
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;	
			double nextDist = cost * adj[here][i].second;
			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push(make_pair(-1.0 * nextDist, there));	
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		adj[i].clear();
	}
	for(int i=0; i<m; ++i) {
		int u, v;
		double w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	dijkstra(0);
	cout << fixed;
	cout.precision(10);
	cout << dist[n-1] << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;	
}

