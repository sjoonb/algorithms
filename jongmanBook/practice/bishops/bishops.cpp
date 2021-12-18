#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[2] = {-1, 1};
const int dy[2] = {1, 1};

vector<string> board;

int id[2][8][8];

int n, m;
bool adj[64][64];

vector<bool> visited;
vector<int> aMatch, bMatch;

bool dfs(int a) {
	if(visited[a]) return false;
	visited[a] = true;
	for(int b=0; b<m; ++b)
		if(adj[a][b])
			if(bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
	return false;	
}

int bipartiteMatch() {
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);
	int size=0;
	for(int start=0; start<n; ++start) {
		visited = vector<bool>(n, false);
		if(dfs(start))
			size++;
	}
	return size;	
}

bool inRange(int y, int x) {
	return (0<=y && y<board.size() && 0<=x && x<board.size());
}

int placeBishops() {
	memset(id, -1, sizeof(id));	
	int count[2] = {0, 0};
	for(int dir=0; dir<2; ++dir)
		for(int y=0; y<board.size(); ++y)
			for(int x=0; x<board.size(); ++x)
				if(board[y][x] == '.' && id[dir][y][x] == -1) {
					int cy=y, cx=x;
					while(inRange(cy, cx) && board[cy][cx] == '.') {
						id[dir][cy][cx] = count[dir];		
						cy += dy[dir];
						cx += dx[dir];
					}
					count[dir]++;
				}
	n = count[0];
	m = count[1];
	memset(adj, 0, sizeof(adj));
	for(int y=0; y<board.size(); ++y)
		for(int x=0; x<board.size(); ++x)
			if(board[y][x] == '.')
				adj[id[0][y][x]][id[1][y][x]] = true;
	return bipartiteMatch();
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int h;
		cin >> h;
		board = vector<string>(h);
		for(int i=0; i<h; ++i)
			cin >> board[i];
		cout << placeBishops() << "\n";
	}
}
