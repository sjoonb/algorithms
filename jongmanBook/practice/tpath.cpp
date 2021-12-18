#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int V, E;

const int MAX_V = 2000;

vector<pair<int, int> > adj[MAX_V];
vector<int> weights;

vector<pair<int, pair<int, int> > > edges;

struct DisjointSet {
  vector<int> parent, rank;

  DisjointSet(int n) : parent(n), rank(n, 1) {
    for(int i = 0; i < n; i++)
      parent[i] = i;
  }

  // u 가 속한 트리의 루트의 번호를 반환한다
  int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  // u 가 속한 트리와 v 가 속한 트리를 합친다
  void merge(int u, int v) {
    u = find(u); v = find(v);
    // 이미 둘이 같은 트리에 속한 경우
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    // 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
    if(rank[u] == rank[v]) rank[v]++;
    parent[u] = v;
  }
};

int seen[2000];

bool dfs(int here, int lo, int hi) {
  if(here == V-1) return true;
  seen[here] = 1;
  for(int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i].first, edge = adj[here][i].second;
    if(edge < lo || hi < edge || seen[there]) continue;
    if(dfs(there, lo, hi)) return true;
  }
  return false;
}


bool hasPath(int lo, int hi) {
  memset(seen, 0, sizeof(seen));
  return dfs(0, lo, hi);
}

int binarySearchMinUpperBound(int low) {
  // 반복문 불변식:
  // 1. 가중치가 [weights[low], weights[lo]]
  // 범위에 있는 간선을 사용하면 두 정점을 연결할 수 없다.
  // 2. 가중치가 [weights[low], weights[hi]] 범위에 있는
  // 간선을 사용하면 두 정점을 연결할 수 있다.
  int lo = low-1, hi = weights.size();
  while(lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if(hasPath(weights[low], weights[mid]))
      hi = mid;
    else lo = mid;
  }
  if(hi == weights.size())
    return 987654321;
  return weights[hi];
}


int kruskalMinUpperBound(int low) {
	DisjointSet sets(V);
	for(int i=0; i<edges.size(); ++i) {
		if(edges[i].first < weights[low]) continue;		
		// edges[i] 를 그래프에 추가하자
	sets.merge(edges[i].second.first, edges[i].second.second);

	// 0과 V-1이 연결되었다면 마지막에 추가한 간선의 가중치를 반환한다.
	if(sets.find(0) == sets.find(V-1))
	  return edges[i].first;
  }
  return 987654321;
}

int minUpperBound(int low) {
//	return kruskalMinUpperBound(low);
	return binarySearchMinUpperBound(low);
}

int minWeightDifference() {
	int ret = INF;
	for(int i=0; i<weights.size(); ++i)
		ret = min(ret, minUpperBound(i) - weights[i]);
	return ret;	
}

vector<int> collectWeights() {
  vector<int> weights;
  // 모든 간선의 가중치를 저장한다
  for(int i = 0; i < V; ++i)
    for(int j = 0; j < adj[i].size(); ++j)
      weights.push_back(adj[i][j].second);
  // 정렬하고 중복을 제거한다
  sort(weights.begin(), weights.end());
  weights.erase( unique(weights.begin(), weights.end()), weights.end() );
  return weights;
}



void solve() {
	cin >> V >> E;
	edges.resize(E);
	for(int i=0; i<V; ++i) adj[i].clear();
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = make_pair(w, make_pair(u, v));
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	sort(edges.begin(), edges.end());
	weights = collectWeights();
	cout << minWeightDifference() << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
