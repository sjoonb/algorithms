#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int v, e;

// for kruskal
priority_queue<pair<int, pair<int, int> > > pq; 
vector<pair<int, pair<int, int> > > edgeList;
vector<int> parent;
vector<int> rnk;

void prim() {

}



void initQueue() {
	for(int i=0; i<e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		//pq.push(make_pair(-w, make_pair(u, v)));
		edgeList.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(edgeList.begin(), edgeList.end());
}

void initParent() {
	parent = vector<int>(v+1, 0);
	for(int i=1; i<=v; ++i) {
		parent[i] = i;
	}
}

int find(int x) {
	if(parent[x] == x)
		return x;
	else
		return find(parent[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);

	if(rnk[x] > rnk[y]) {
		parent[y] = x;
	} else {
		parent[x] = y;
	}
	if(rnk[x] == rnk[y])
		rnk[y]++;
}


int kruskal() {
	initQueue();
	initParent();
	rnk = vector<int>(v+1, 0);
	int edgeCnt = 0;
	int ret = 0;
	for(int i=0; i<edgeList.size(); ++i) {
		if(edgeCnt >= v-1)
			return ret;	
		pair<int, pair<int, int> > edge = edgeList[i];
		int u = edge.second.first;
		int v = edge.second.second;
		int w = edge.first;
		//edgeList.erase(edgeList.begin());

		if(find(u) != find(v)) {
			merge(u, v);
			ret += w;
			edgeCnt++;
		}
	}
	return ret;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string algorithm = argv[argc-1];
	cin >> v >> e;
	if(algorithm == "prim") {
		prim();
	} else {
		cout << kruskal();
	}
}
