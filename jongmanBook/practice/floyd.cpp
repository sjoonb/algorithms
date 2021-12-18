#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

const int MAX_V = 101;

int v;
int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void floyd() {
	memset(via, -1, sizeof(via));
	for(int k=1; k<=v; ++k)
		for(int i=1; i<=v; ++i)
			for(int j=1; j<=v; ++j) {
				if(adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					via[i][j] = k;
				}
			}
}

void reconstruct(int a, int b, vector<int>& path) {
	if(via[a][b] == -1) {
		path.push_back(a);
		if(a != b) path.push_back(b);
	} else {
		int w = via[a][b];
		reconstruct(a, w, path);
		path.pop_back();
		reconstruct(w, b, path);
	}
}

int main() {
	int e;
	cin >> v >> e;
	for(int i=1; i<=v; ++i)
		for(int j=1; j<=v; ++j) {
			if(i==j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
		}
	for(int i=0; i<e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a][b] = w;
	}
	floyd();
//	for(int i=1; i<=v; ++i) {
//		for(int j=1; j<=v; ++j)
//			cout << adj[i][j] << " ";
//		cout << "\n";
//	}
	vector<int> path;
	reconstruct(1, 3, path);
	for(int i: path)
		cout << i << " ";
	return 0;
}
