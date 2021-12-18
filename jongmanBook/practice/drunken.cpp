#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

int V, adj[500][500];
int delay[500];
int W[500][500];

void solve() {
	vector<pair<int, int> > order;
	for(int i=0; i<V; ++i)
		order.emplace_back(delay[i], i);
	sort(order.begin(), order.end());
	for(int i=0; i<V; ++i)
		for(int j=0; j<V; ++j)
			if(i==j)
				W[i][j] = 0;
			else
				W[i][j] = adj[i][j];
	int ret = INF;
	for(int k=0; k<V; ++k) {
		int w = order[k].second;
		for(int i=0; i<V; ++i)
			for(int j=0; j<V; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
				W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
			}
	}
}

int main() {
	int E;
	cin >> V >> E;
	for(int i=0; i<V; ++i)
		for(int j=0; j<V; ++j)
			if(i==j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
	for(int i=0; i<V; ++i) cin >> delay[i];
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u][v] = w;	
		adj[v][w] = w;
	}
	solve();
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << W[a][b] << endl;
	}
	return 0;	
}
