#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<bool> finished;
int cnt;

void makeGraph() {
	int n, e;
	cin >> n >> e;
	adj = vector<vector<int> >(n, vector<int>(n));
	discovered = vector<int>(n, -1);
	finished = vector<bool>(n, false);
	for(int i=0; i<e; ++i) {
		int u, v;
		cin >> u >> v;	
		adj[u][v]++;
	}
}

void dfsEdge(int here) {
	discovered[here] = cnt++;
	for(int there=0; there<adj[here].size(); ++there) {
		if(adj[here][there]) {
			adj[here][there]--;
			if(discovered[there] == -1) {
				cout << here << "->" << there << " is tree edge\n";
				dfsEdge(there);
			} else if(discovered[there] > discovered[here]) {
				cout << here << "->" << there << " is forward edge\n";
			} else if(!finished[there]) {
				cout << here << "->" << there << " is backward edge\n";
			} else {
				cout << here << "->" << there << " is cross edge\n";
			}
		}
	}
	finished[here] = true;
}

int main() {
	makeGraph();
	dfsEdge(0);
}
