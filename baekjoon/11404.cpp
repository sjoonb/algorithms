#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, M;
int graph[101][101];

void floyd() {
	for(int k=1; k<=N; ++k)
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j) 
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; ++i)
		for(int j=1; j<= N; ++j)
			if(i != j)
				graph[i][j] = INF;
	for(int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = min(graph[u][v], w);
	}
	floyd();
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j)
			cout << graph[i][j] == INF ? 0 : graph[i][j]) << " ";
		cout << "\n";
	}
	return 0;	
}

