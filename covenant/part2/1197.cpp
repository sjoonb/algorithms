#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;

// for kruskal
priority_queue<pair<int, pair<int, int> > > pq; 
vector<int> parent;
vector<int> rnk;

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
	while(!pq.empty() && edgeCnt < v-1) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = -pq.top().first;
		pq.pop();

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
