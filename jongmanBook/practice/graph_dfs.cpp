#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj{ {1, 2} };
vector<bool> visited;

void dfs(int here) {
	visited[here] = true;
	for(int i=0; i<adj[here].size(); ++i) {
		int there = adj[here][i];
		if(!visited[there])
			dfs(there);
	}
}

void dfs_all() {
	for(int i=0; i<adj.size(); ++i) {
		if(!visited[i])
			dfs(i);	
	}
}
