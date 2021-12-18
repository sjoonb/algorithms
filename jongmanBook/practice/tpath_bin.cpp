#include <iostream>
#include <vector>
using namespace std;


int V, E;
vector<pair<int, int> > adj[2000];

void sovle() {
	cin >> V >> E;	
	edges.resize(E);
	for(int i=0; i<V; ++i) adj[i].clear();
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = make_pair(w, make_pair(u, v));
	}
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
