#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int visitCnt[1000][1000];
char gym[1000][1000];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

int solve(int y, int x, int destY, int destX) {
	queue<pair<int, int> > q; // y, x;
	q.push(make_pair(y, x));
	visitCnt[y][x] = 1;
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if(cy == destY && cx == destX) {
			return visitCnt[cy][cx] - 1;
		}
		for(int k=0; k<4; ++k) {
			for(int l=1; l<=K; ++l) {
				int ny = cy + dy[k] * l;
				int nx = cx + dx[k] * l;
				if(!inRange(ny, nx) || gym[ny][nx] == '#')
					break;

				if(visitCnt[ny][nx] == 0) {
					q.push(make_pair(ny, nx));	
					visitCnt[ny][nx] = visitCnt[cy][cx] + 1;
				} else if(visitCnt[ny][nx] <= visitCnt[cy][cx]) {
					break;
				}	
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;	
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			cin >> gym[i][j];
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;
	cout << solve(y1-1, x1-1, y2-1, x2-1);
}
