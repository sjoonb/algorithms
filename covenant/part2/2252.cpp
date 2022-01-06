#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> adjL[32001];
vector<int> res;

bool isVisited[32001]; // false by default in global

void dfs(int here) {
	isVisited[here] = true;
	for(int i=0; i<adjL[here].size(); ++i) {
		int next = adjL[here][i];	
		if(!isVisited[next])
			dfs(next);
	}
	res.push_back(here);
}

int main() {
	cin >> N >> M;	
	for(int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v;
		adjL[u].push_back(v);
	}
	for(int i=1; i<=N; ++i) {
		if(!isVisited[i])
			dfs(i);
	}
	reverse(res.begin(), res.end());
	for(int i=0; i<res.size(); ++i)
		cout << res[i] << " ";
}
