#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

string board[100];
bool adj[100][100];

int H, W;
int n, m;

vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a) {
	if(visited[a]) return false;
	visited[a] = true;
	for(int b=0; b<m; ++b) {
		if(bMatch[b] == -1 || dfs(bMatch[b])) {
			aMatch[a] = b;
			bMatch[b] = a;
			return true;	
		}
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
	return (y>=0 && y<H && x>=0 && x<W);	
}

bool fillDomino() {
	vector<vector<int> > id(H, vector<int>(W, -1));
	n = m = 0;
	for(int y=0; y<H; ++y)
		for(int x=0; x<W; ++x)
			if(board[y][x] != '#') {
				if((y+x)%2==0)
					id[y][x] = n++;
				else
					id[y][x] = m++;
			}
	memset(adj, 0, sizeof(adj));
	for(int cy=0; cy<H; ++cy)
		for(int cx=0; cx<W; ++cx)
			if((cy+cx)%2==0 && board[cy][cx] != '#') {
				for(int k=0; k<4; ++k) {
					int ny = cy+dy[k];
					int nx = cx+dx[k];
					if(inRange(ny, nx) && board[ny][nx] != '#')
						adj[id[cy][cx]][id[ny][nx]] = true;
				}
			}
	return bipartiteMatch()*2 == (n+m);
}

int main() {
	cin >> H >> W;
	for(int i=0; i<H; ++i) {
		cin >> board[i];
	}
	(fillDomino() ? cout << "canFill!" : cout << "nope");
	return 0;
}
