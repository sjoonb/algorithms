#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int u, v, w;
};

#define INF 987654321
#define ll long long

int N, M;
vector<ll> dist;
vector<Edge> edgeList;

bool bellman() {
	dist[1] = 0;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			int u = edgeList[j].u;	
			int v = edgeList[j].v;	
			int w = edgeList[j].w;	
			if(dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if(i == N-1)
					return false;
			}

		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	dist = vector<ll>(N+1, INF);
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edgeList.push_back({u, v, w});
	}
	if(bellman() == true) {
		for(int i=2; i<=N; ++i)
			cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
	} else {
		cout << -1;
	}
	return 0;	
}

