#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321
const int MAX_V = 1000;

int v;
vector<pair<int, int> > adj[MAX_V];

vector<int> bellmanFord(int src) {
	vector<int>	upper(v, INF);
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

void solve() {
	int e;
	cin >> v >> e;
	for(int i=0; i<v; ++i)
		adj[i].clear();
	for(int i=0; i<e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);			
	}
	vector<int> shortest = bellmanFord(0);
	if(!shortest.empty())
		for(int i=0; i<shortest.size(); ++i)
			cout << shortest[i] << " ";
	else
		cout << -1;
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;	
}
