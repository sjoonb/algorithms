#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;

// for prim
vector<vector<pair<int, int> > > graph;

// for kruskal
priority_queue<pair<int, pair<int, int> > > pq; 
vector<int> parent;

void initQueue() {
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push(make_pair(-w, make_pair(u, v)));
	}
}

void initParent() {
	parent = vector<int>(V+1, 0);
	for(int i=1; i<=V; ++i) {
		parent[i] = i;
	}
}

int find(int x) {
	if(parent[x] == x)
		return x;
	else
		return find(parent[x]);
}


int kruskal() {
	initQueue();
	initParent();
	int edgeCnt = 0;
	int ret = 0;
	while(!pq.empty() && edgeCnt < V-1) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = -pq.top().first;
		pq.pop();

		if(find(u) != find(v)) {
			parent[find(v)] = u;
			ret += w;
			edgeCnt++;
		}
	}
	return ret;
}

void initGraph() {
	graph = vector<vector<pair<int, int> > >(V+1);
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
}

int prim(int src = 1) {
	initGraph();	
	int edgeCnt = 0;
	int ret = 0;
	vector<bool> isPrimSet(V+1, false);
	priority_queue<pair<int, int> > primPq; // (-w, v)
	primPq.push(make_pair(0, src));
	while(!primPq.empty() && edgeCnt <= V-1) {
		int cand = primPq.top().second;
		int candWeight = -primPq.top().first;
		primPq.pop();
		if(isPrimSet[cand])
			continue;
		for(int i=0; i<graph[cand].size(); ++i) {
			int next = graph[cand][i].first;	
			int nextWeight = -graph[cand][i].second;
			primPq.push(make_pair(nextWeight, next));
		}
		edgeCnt += 1;
		ret += candWeight;
		isPrimSet[cand] = true;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	string algorithm = argv[argc-1];
	cin >> V >> E;
	if(algorithm == "kruskal") {
		cout << kruskal();
	} else {
		cout << prim();
	}
}
