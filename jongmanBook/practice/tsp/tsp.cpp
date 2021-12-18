#include <iostream>
#include <vector>
using namespace std;

int n;
int dist[100][100];

const double INF = 1e9;
const int MAX = 30;

double cache[MAX][1<<MAX];

double shortestPath2(int here, int visited) {
	if(visited == (1<<n)-1) return dist[here][0];
	double& ret = cache[here][visited];
	if(ret != -1.0) return ret;
	ret = INF;
	for(int next=0; next<n; ++next) {
		if(visited & (1<<next)) continue;
		double cand = dist[here][next] + shortestPath2(next, visited + (1<<next));
		ret = min(ret, cand);
	}
	return ret;
}

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	if(path.size() == n)
		return currentLength + dist[0][path.back()];
	double ret = INF;
	for(int i=0; i<n; ++i) {
		if(visited[i]) continue;	
		visited[n] = true;
		int here = path.back();
		path.push_back(n);
		double cand = shortestPath(path, visited, currentLength+dist[here][n]);
		ret = min(ret, cand);
		visited[n] = false;
		path.pop_back();
	}
	return ret;
}

int main() {
//	for(int i=0; i<(1<<MAX); ++i)
//		cache[0][i] = 1;
	cout << (1<<MAX);
}
