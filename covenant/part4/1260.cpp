#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<bool> > adjM;

// for dfs
vector<bool> isVisited;

void dfs(int src) {
	isVisited[src] = true;
	cout << src << " ";

	for(int next=1; next<=N; ++next) {
		if(adjM[src][next] && !isVisited[next])
			dfs(next);
	}
}

void bfs(int src) {
	queue<int> q;	
	q.push(src);
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		if(isVisited[here])
			continue;
		isVisited[here] = true;
		cout << here << " ";
		for(int next=1; next<=N; ++next)
			if(adjM[here][next])
				q.push(next);
	}
}

int main() {
	cin >> N >> M >> V;
	adjM = vector<vector<bool> >(N+1, vector<bool>(N+1, false));
	isVisited = vector<bool>(N+1, false);
	for(int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v;
		adjM[u][v] = true;
		adjM[v][u] = true;
	}
	dfs(V);
	cout << endl;
	isVisited = vector<bool>(N+1, false);
	bfs(V);
}


