#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;
bool isVisited[20001];
int colors[20001];
vector<vector<int> > graph;

bool dfs(int here, int color) {
	isVisited[here] = true;
	colors[here] = color;
	for(int i=0; i<graph[here].size(); ++i) {
		int there = graph[here][i];
		if(isVisited[there]) {
			if(colors[there] == colors[here])
				return false;
		} else  {
			if(!dfs(there, color ? 0 : 1))
				return false;
		}
	}
	return true;	
}

bool solve() {
	for(int i=1; i<=V; ++i) 
		if(!isVisited[i]) {
			if(!dfs(i, 0))
				return false;
		}
	return true;	
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		memset(isVisited, false, sizeof(isVisited));
		memset(colors, -1, sizeof(colors));
		cin >> V >> E;
		graph = vector<vector<int> >(V+1);
		for(int i=0; i<E; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cout << (solve() == true ? "YES" : "NO");
		cout << "\n";
	}
	return 0;	
}
