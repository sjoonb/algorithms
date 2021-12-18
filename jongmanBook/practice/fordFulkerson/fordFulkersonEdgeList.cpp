#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int target, capacity, flow;
	Edge* reverse;
	int residualCapacity() const { return capacity - flow; }
	void push(int amt) {
		flow += amt;
		reverse-> flow -= amt;
	}
};

int V, E;
const int MAX_V = 100;
const int INF = 987654321;

vector<Edge*> adj[MAX_V];


int fordFulkerson(int source, int sink) {
	int totalFlow = 0;
	while(true) {
		vector<int> parent(MAX_V, -1);	
		vector<Edge*> parentEdge(V);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1)  {
			int here = q.front(); q.pop();
			for(int i=0; i<adj[here].size(); ++i) {
				Edge* currEdge = adj[here][i];
				int there = currEdge->target;
				if(currEdge->residualCapacity() > 0 && parent[there] == -1) {
					parent[there] = here;
					parentEdge[there] = currEdge;
					q.push(there);
				}
			}

		}
		if(parent[sink] == -1) break;
		int amt = INF;
		for(int p=sink; p != source; p=parent[p]) {
			amt = min(amt, parentEdge[p]->residualCapacity());
		}
		for(int p=sink; p != source; p=parent[p]) {
			parentEdge[p]->push(amt);
		}
		totalFlow += amt;
	}
	return totalFlow;	
}

void addEdge(int u, int v, int capacity) {
	Edge* uv = new Edge(), *vu = new Edge();	
	uv->target = v;
	uv->capacity = capacity;
	uv->flow = 0;
	uv->reverse = vu;
	
	vu->target = u;
	vu->capacity = 0;
	vu->flow = 0;
	vu->reverse = uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);

}

int main() {
	cin >> V >> E;
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
	}
	cout << fordFulkerson(0, V-1) << "\n";
//	for(int i=0; i<V; ++i) {
//		for(int j=0; j<adj[i].size(); ++j)
//			delete adj[i][j];
//		adj[i].clear();
//	}
	return 0;
}
