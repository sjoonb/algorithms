#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 2000;
vector<pair<int, int>> adj[MAX_V];
vector<int> weights;
int seen[MAX_V];

int V, E;

vector<int> collectWeights() {
	vector<int> weights;
	for(int i=0; i<V; ++i)
		for(int j=0; j<adj[i].size(); ++j)
			weights.push_back(adj[i][j].second);
	sort(weights.begin(), weights.end());
	weights.erase(unique(weights.begin(), weights.end()), weights.end());
	return weights;
}

bool dfs(int here, int lo, int hi) {
	if(here == V-1) return true;
	seen[here] = 1;	
	for(int i=0; i<adj[here].size(); ++i) {
		int there = adj[here][i].first;
		int edge = adj[here][i].second;
		if(edge < lo || edge > hi || seen[there]) continue;
		if(dfs(there, lo, hi)) return true;
	}
	return false;
}

bool hasPath(int lo, int hi) {
	memset(seen, 0, sizeof(seen));
	return dfs(0, lo, hi);
}

int brute() {
	int ret = 987654321;
	for(int lo=0; lo<weights.size(); ++lo)
		for(int hi=lo; hi<weights.size(); ++hi) {
			if(hasPath(weights[lo], weights[hi])) {
				ret = min(ret, weights[hi] - weights[lo]);
				break;
			}
		}
	return ret;
}

int optimized() {
	int ret = 987654321, foundPathUsing = 0;
	for(int lo=0; lo<weights.size(); ++lo) {
		bool foundPath = false;
		for(int hi=foundPathUsing; hi<weights.size(); ++hi) {
			if(hasPath(weights[lo], weights[hi])) {
				ret = min(ret, weights[hi] - weights[lo]);		
				foundPath = true;
				foundPathUsing = hi;
				break;
			}
		}
		if(!foundPath) break;
	}
	return ret;
}

int scanning() {
	int lo=0, hi=0, ret = 987654321;
	while(lo <weights.size() && hi <weights.size()) {
		if(hasPath(weights[lo], weights[hi])) {
			ret = min(ret, weights[hi] - weights[lo]);
			++lo;
		} else {
			++hi;
		}
		cout << lo << " " << hi << "\n";
	}
	cout << "\n";
	return ret;
}

void solve() {
	cin >> V >> E;	
	for(int i=0; i<V; ++i) adj[i].clear();
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	weights = collectWeights();
	cout << scanning() << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;	
}
