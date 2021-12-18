#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

int v;
const int MAX_V = 100;

vector<pair<int, int> > adj[MAX_V];
vector<pair<int, int> > iadj[MAX_V];

vector<int> bellmanFord(int src, const vector<pair<int ,int> > adj[MAX_V]) {
	vector<int> upper(v, INF);
	upper[src] = 0;
	bool updated;
	for(int iter=0; iter<v; ++iter) {
		updated = false;
		for(int here=0; here<v; ++here) 
			for(int i=0; i<adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if(upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;		
				}
			}
		if(!updated) break;
	}
	if(updated) upper.clear();
	return upper;
}

bool reachable[MAX_V][MAX_V];

int bellman2(int src, int target) {
	vector<int> upper(v, INF);
	upper[src] = 0;
	for(int iter = 0; iter<v-1; ++iter)
		for(int here=0; here<v; ++here)
			for(int i=0; i<adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				upper[there] = min(upper[there], upper[here] + cost);
			}
	for(int here=0; here<v; ++here)
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			if(upper[here] + cost < upper[there])
				if(reachable[src][here] && reachable[here][target])
					return -INF;
		}
	return upper[target];
}

void solve() {
	int e;
	cin >> v >> e;	
	for(int i=0; i<v; ++i) {
		adj[i].clear();
		iadj[i].clear();
	}
	for(int i=0; i<e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		iadj[a].emplace_back(b, -w);
	}
	vector<int> ret = bellmanFord(0, adj);
	vector<int> iret = bellmanFord(0, iadj);

	if(ret[1] > 10e6) {
		cout << "UNREACHABLE";

	} else {
		if(!ret.empty())
			cout << ret[1];
		else
			cout << "INFINITY";
		cout << " ";

		if(!iret.empty())
			cout << -1*iret[1];
		else
			cout << "INFINITY";
		cout << " ";
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;	
}
