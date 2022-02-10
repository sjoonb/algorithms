#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int V;
bool isVisited[100001];
bool isInLine[100001];
vector<vector<pair<int, int> > > graph;

int dfs(int here) {
	isVisited[here] = true;
	int ret = 0;
	int candNode = -1;
	for(int i=0; i<graph[here].size(); ++i) {
		int there = graph[here][i].first;
		int dist = graph[here][i].second;
		if(!isVisited[there]) {
			int candDist = dfs(there) + dist;
			if(candDist > ret) {
				ret = candDist;	
				candNode = there;
			}
		}
	}
	if(candNode != -1)
		isInLine[candNode] = true;
	return ret;
}

int solve() {
	int ret = 0;
	for(int src=1; src<=V; ++src) {
		if(!isInLine[src]) {
			isInLine[src] = true;
			memset(isVisited, false, sizeof(isVisited));	
			ret = max(ret, dfs(src)); 
		}
	}
	return ret;
}

int main() {
	cin >> V;
	graph = vector<vector<pair<int, int> > >(V+1);
	for(int i=0; i<5; ++i) {
		int u, v, w;	
		cin >> u;
		while(true) {
			cin >> v;	
			if(v == -1)
				break;
			cin >> w;
			graph[u].push_back(make_pair(v, w));
		}
	}
	cout << solve();
	return 0;	
}
