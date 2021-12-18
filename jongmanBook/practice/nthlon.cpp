#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

const int V = 402;
vector<pair<int, int> > adj[V];
const int START = V-1;

int vertex(int delta) {
	return delta + 200;
}

vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.emplace(0, src);
	while(!pq.empty()) {
		int here = pq.top().second;	
		int cost = -pq.top().first;
		pq.pop();
		if(cost > dist[here]) continue;
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.emplace(-nextDist, there);
			}
		}
	}
	return dist;
}

int nthlon(const vector<int>& a, const vector<int>& b) {
	for(int i=0; i<V; ++i) adj[i].clear();
	for(int i=0; i<a.size(); ++i) {
		int delta = a[i] - b[i];
		adj[START].push_back(make_pair(vertex(delta), a[i]));
	}
	for(int delta = -200; delta<=200; ++delta) {
		for(int i=0; i<a.size(); ++i) {
			int next = delta + a[i] - b[i];
			if(abs(next) > 200) continue;
			adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
		}
	}
	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	if(ret == INF)
		cout << "IMPOSSIBLE";
	else
		cout << ret;
	cout << "\n";
	return 0;	
}

void solve() {
	int m;
	cin >> m;
	vector<int> a(m), b(m);
	for(int i=0; i<m; ++i) 
		cin >> a[i] >> b[i];
	int ret = nthlon(a, b);	
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;	
}
