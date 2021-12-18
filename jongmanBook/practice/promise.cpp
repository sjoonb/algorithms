#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int v, adj[200][200];

void floyd() {
	for(int k=0; k<v; ++k)	
		for(int i=0; i<v; ++i)
			for(int j=0; j<v; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

bool update(int a, int b, int c) {
	if(adj[a][b] <= c)
		return false;
	for(int x=0; x<v; ++x)
		for(int y=0; y<v; ++y)
			adj[x][y] = min(adj[x][y], min(adj[x][a] + c + adj[b][y], adj[x][b] + c + adj[a][y]));
	return true;
}

int solve() {
	int m, n;
	cin >> v >> m >> n;	
	for(int i=0; i<v; ++i)
		for(int j=0; j<v; ++j)
			if(i==j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
	for(int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		c = min(adj[a][b], c);
		adj[a][b] = c;
		adj[b][a] = c;
	}
	floyd();	
	int ret=0;
	for(int i=0; i<n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if(!update(a, b, c))
			ret++;
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cout << solve() << "\n";
	}
	return 0;
}
