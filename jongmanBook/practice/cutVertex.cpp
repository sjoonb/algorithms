#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<bool> cutVertex;
int cnt;

void makeGraph() {
	int n, e;
	cin >> n >> e;	
	adj = vector<vector<int> >(n, vector<int>(n, 0));
	discovered = vector<int>(n, -1);
	cutVertex = vector<bool>(n, false);
	for(int i=0; i<e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
}

int dfs(int here, bool isRoot = true) {
	discovered[here] = cnt++;
	int ret = discovered[here];
	int child = 0;
	for(int there=0; there<adj[here].size(); ++there) {
		if(adj[here][there]) {
			if(discovered[there] == -1) {
				child++;
				int subtree = dfs(there, false);
				if(!isRoot && subtree >= discovered[here]) 
					cutVertex[here] = true;
			} else {
				ret = min(ret, discovered[there]);
			}
		}
	}
	if(isRoot) cutVertex[here] = child >= 2;
	return ret;
}

int main() {
	makeGraph();
	dfs(4);
	cout << "result: ";
	for(int i=0; i<cutVertex.size(); ++i)
		if(cutVertex[i])
			cout << i;
	cout << "\n";
}
