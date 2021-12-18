#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> >adj;
vector<bool> visited;

const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int ans;

int dfs(int here) {
	visited[here] = true;
	int children[3] = {0, 0, 0};
	for(int i=0; i<adj[here].size(); ++i) {
		int there = adj[here][i];
		if(!visited[there])
			children[dfs(there)]++;
	}
	if(children[UNWATCHED]) {
		ans++;
		return INSTALLED;
	}
	else if(children[INSTALLED]) {
		return WATCHED;
	}
	return UNWATCHED;
}

void solve() {
	int n, e;
	cin >> n >> e;
	ans = 0;
	visited = vector<bool>(n, false);
	adj = vector<vector<int> >(n, vector<int>());
	for(int i=0; i<e; ++i) {
		int u, v;
		cin >> u >> v;	
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<n; ++i) {
		if(!visited[i])
			if(dfs(i) == UNWATCHED)
				ans++;
	}
	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}







