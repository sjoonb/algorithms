#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> aMatch, bMatch;
vector<bool> visited, aChosen, bChosen;

vector<string> board;

bool adj[200][200];
int id[20][20];

int n, m;
int H, W;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

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
		visited = vector<bool>(n);
		if(dfs(start))
			size++;
	}
	return size;	
}

int calcMaxIndependentSet() {
	bipartiteMatch();	
	aChosen = vector<bool>(n, true);
	bChosen = vector<bool>(m, false);
	for(int i=0; i<m; ++i)
		if(bMatch[i] == -1)
			bChosen[i] = true;
	while(true) {
		bool changed = false;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(aChosen[i] && bChosen[j] && adj[i][j]) {
					aChosen[i] = false;
					bChosen[aMatch[i]] = true;
					changed = true;
				}
		if(!changed) break;
	}
	int ret=0;
	for(int i=0; i<H; ++i)
		for(int j=0; j<W; ++j)
			if(board[i][j] != '#') {
				if((i+j)%2==0) {
					if(aChosen[id[i][j]]) {
						board[i][j] = '^';
						ret++;			
					}
				}
				else {
					if(bChosen[id[i][j]]) {
						board[i][j] = '^';
						ret++;
					}
				}
			}
	return ret;
}

bool inRange(int y, int x) {
	return (y>=0 && y<H && x>=0 && x<W);
}

void makeGraph() {
	memset(adj, false, sizeof(adj));
	memset(id, -1, sizeof(id));
	n = m = 0;
	for(int i=0; i<H; ++i)
		for(int j=0; j<W; ++j) 
			if(board[i][j] != '#') {
				if((i+j)%2==0)
					id[i][j] = n++;
				else	
					id[i][j] = m++;
			}
	for(int cy=0; cy<H; ++cy)
		for(int cx=0; cx<W; ++cx)
			if((cy+cx)%2==0	&& board[cy][cx] != '#') {
				for(int k=0; k<4; ++k) {
					int ny = cy + dy[k];
					int nx = cx + dx[k];
					if(inRange(ny, nx) && board[ny][nx] != '#')
						adj[id[cy][cx]][id[ny][nx]] = true;
				}
			}
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> H >> W;
		board.resize(H);
		for(int i=0; i<H; ++i)
			cin >> board[i];
		makeGraph();
		cout << calcMaxIndependentSet() << "\n";
		for(int i=0; i<H; ++i)
			cout << board[i] << "\n";
	}
	return 0;	
}
