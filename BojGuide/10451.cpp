#include <iostream>
#include <cstring>
using namespace std;

int N;
int graph[1001];
bool currentCycle[1001];
bool isVisited[1001];

bool isCycle(int src) {
	isVisited[src] = true;
	currentCycle[src] = true;
	int next = graph[src];
	if(currentCycle[next])
		return true;
	if(!isVisited[next])
		return isCycle(next);
	return false;	
}

int solve() {
	memset(isVisited, false, sizeof(isVisited));
	int ret = 0;	
	for(int i=1; i<=N; ++i) {
		memset(currentCycle, false, sizeof(currentCycle));
		if(!isVisited[i] && isCycle(i))
			ret++;
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		cin >> N;	
		for(int u=1; u<=N; ++u) {
			int v;
			cin >> v;
			graph[u] = v;
		}
		cout << solve() << "\n";
	}
	return 0;
}
