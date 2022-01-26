#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool> > adjM;
vector<bool> isVisited;

int dfs(int src) {
	if(isVisited[src])
		return 0;
	isVisited[src] = true;
	int ret = 1;
	for(int next=1; next<= N; ++next) {
		if(adjM[src][next])
			ret += dfs(next);
	}
	return ret;
}

int main() {
	cin >> N >> M;
	adjM = vector<vector<bool> >(N+1, vector<bool>(N+1, false));
	isVisited = vector<bool>(N+1, false);
	for(int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v;
		adjM[u][v] = true;
		adjM[v][u] = true;
	}
	cout << dfs(1) - 1;
}
