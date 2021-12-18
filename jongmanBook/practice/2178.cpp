#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

vector<vector<int> > adj;

bool inRange(int y, int x) {
	return (y >= 0 && y < adj.size()) && (x >=0 && x <adj[0].size());
}

void bfs(int y, int x) {
	vector<vector<int> > discovered(adj.size(), vector<int>(adj[0].size(), 0));
	queue<pair<int, int>> q;
	discovered[y][x] = 1;
	q.push(make_pair(y, x));
	while(!q.empty()) {
		pair<int, int> here = q.front();
		q.pop();
		for(int i=0; i<4; ++i) {
			int ny = here.first + dy[i];	
			int nx = here.second + dx[i];	
			if(inRange(ny, nx) && adj[ny][nx] && !discovered[ny][nx]) {
				q.push(make_pair(ny, nx));	
				discovered[ny][nx] = discovered[here.first][here.second]+1;
			}
		}
	}
	cout << discovered[adj.size()-1][adj[0].size()-1];
}

void solve() {
	bfs(0, 0);	
}

int main() {
	int r, c;
	cin >> r >> c;
	adj = vector<vector<int> >(r, vector<int>(c, 0));
	for(int i=0; i<r; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); ++j) {
			adj[i][j] = s[j] - '0';
		}
	}
	solve();
}
