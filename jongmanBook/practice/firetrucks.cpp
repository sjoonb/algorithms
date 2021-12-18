#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[1001];
vector<int> dist;

int v, e, n, m;

const int INF = 987654321;

void dijkstra(int src) {
	dist = vector<int>(v+1, INF);
	queue<pair<int, int> > q;
	dist[src] = 0;
	q.push(make_pair(0, src));
	while(!q.empty()) {
		int here = q.front().second;
		int cost = -q.front().first;
		q.pop();
		if(cost > dist[here]) continue;
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;	
			int nextDist = cost + adj[here][i].second;
			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				q.push(make_pair(-nextDist, there));
			}
		}
	}
}

void solve() {
	cin >> v >> e >> n >> m;
	for(int i=1; i<=v; ++i) {
		adj[i].clear();
	}
	for(int i=0; i<e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b, w));	
		adj[b].push_back(make_pair(a, w));	
	}
	vector<int> fs = vector<int>(n);
	for(int i=0; i<n; ++i) cin >> fs[i];

	vector<int> fo = vector<int>(m);
	for(int i=0; i<m; ++i) cin >> fo[i];

	for(int i=0; i<fo.size(); ++i) {
		adj[0].emplace_back(fo[i], 0);
		//adj[0].push_back(make_pair(fo[i], 1));
	}

	dijkstra(0);

	long long ret=0;
	for(int i=0; i<fs.size(); ++i) {
		ret += dist[fs[i]];	
	}
	cout << ret << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}
