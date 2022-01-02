#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;

// for kruskal
priority_queue<pair<int, pair<int, int> > > pq; 
vector<int> parent;

void prim() {

}


void initQueue() {
	for(int i=0; i<e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push(make_pair(-w, make_pair(u, v)));
	}
}

void initParent() {
	parent = vector<int>(v+1, 0);
	for(int i=1; i<=v; ++i) {
		parent[i] = i;
	}
}

void _union(int x, int y) {
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
	while(!pq.empty() && edgeCnt < v-1) {
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

int main(int argc, char *argv[]) {
	string algorithm = argv[argc-1];
	cin >> v >> e;
	if(algorithm == "prim") {
		prim();
	} else {
		cout << kruskal();
	}
}
