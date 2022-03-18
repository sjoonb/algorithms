#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
typedef vector<vector<int> > Graph;
Graph graph;
vector<int> colors;

bool bfs(int src) {
	queue<pair<int, int> > q;
	colors[src] = 0;
	q.push({src, colors[src]}); // node, color
	while(!q.empty()) {
		int here = q.front().first;
		int color = q.front().second;
		q.pop();
		for(int i=0; i<graph[here].size(); ++i) {
			int there = graph[here][i];
			if(colors[there] == -1) {
				colors[there] = (color ? 0 : 1);
				q.push({there, colors[there]});	
			} else if(colors[there] == color) {
				return false;	
			}
		}
	}
	return true;
}

bool isBipartite() {
	for(int i=1; i<=V; ++i)
		if(colors[i] == -1)
			if(bfs(i) == false)
				return false;
	return true;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		cin >> V >> E;
		graph = Graph(V+1);
		colors = vector<int>(V+1, -1);
		for(int i=0; i<E; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}	
		cout << (isBipartite() ? "YES" : "NO") << "\n";
	}
	return 0;
}
