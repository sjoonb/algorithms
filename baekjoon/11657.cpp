#include <iostream>
#include <vector>
using namespace std;

#define INF (1 << 30)
#define ll long long

typedef vector<pair<int, pair<int, int> > > EdgeList; // w, u, v;
EdgeList edgeList;
vector<ll> dist;
int N, M;

bool bellman() {
	dist[1] = 0;
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j) {
			int w = edgeList[j].first;
			int u = edgeList[j].second.first;
			int v = edgeList[j].second.second;
			if(dist[u] != INF && dist[v] > dist[u] + w) {
				if(i == N-1)
					return false;
				dist[v] = dist[u] + w;
			}
		}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	edgeList = EdgeList(M);
	dist = vector<ll>(N+1, INF);
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edgeList[i] = {w, {u, v}};
	}
	if(bellman()) {
		for(int i=2; i<=N; ++i)
			cout << (dist[i] != INF ? dist[i] : -1) << "\n";
	} else {
		cout << -1;
	}
	return 0;
}
