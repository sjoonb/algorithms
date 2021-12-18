#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<int> parent;
int cnt;

void makeGraph() {
	int n, e;	
	cin >> n >> e;
	adj = vector<vector<int> >(n, vector<int>(n, 0));
	discovered = vector<int>(n, -1);
	parent = vector<int>(n, -1);
	for(int i=0; i<e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
}

int dfs(int here) {
	discovered[here] = cnt++;
	int ret = discovered[here];
	for(int there=0; there<adj[here].size(); ++there) {
		if(adj[here][there]) {
			if(discovered[there] == -1) {
				parent[there] = here;
				int subTree = dfs(there);
				//cout << subTree;
				if(subTree > discovered[here]) 
					cout << "bridge: " << "(" << here << ", " << there << ")\n";
				ret = min(ret, subTree);
			} else {
				if(parent[here] != there)
					ret = min(ret, discovered[there]);		
			}
		}
	}
	return ret;
}

void clear() {
	discovered = vector<int>(8, -1);
	parent = vector<int>(8, -1);
}

int main() {
	makeGraph();
	for(int i=0; i<8; ++i) {
		cout << "case: " << i << "\n";
		dfs(2);
		clear();
	}
}

