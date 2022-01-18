#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M, K;
bool isVisited[1000][1000];
char gym[1000][1000];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

bool canPassThrough(int y, int x, int ny, int nx) {
	int dy = ny - y;	
	int dx = nx - x;
	if(!dx) {
		if(dy > 0) {
			for(int i=1; i<=dy; ++i)
				if(gym[y+i][x] == '#')
					return false;
		} else {
			for(int i=-1; i>=dy; --i)
				if(gym[y+i][x] == '#')
					return false;
		}
	} else {
		if(dx > 0) {
			for(int i=1; i<=dx; ++i)
				if(gym[y][x+i] == '#')
					return false;
		} else {
			for(int i=-1; i>=dx; --i)
				if(gym[y][x+i] == '#')
					return false;
		}
	}
	return true;
}

int solve(int y, int x, int destY, int destX) {
	queue<tuple<int, int, int> > q; // y, x, depth;
	q.push(make_tuple(y, x, 0));
	isVisited[y][x] = true;
	while(!q.empty()) {
		int cy = get<0>(q.front());
		int cx = get<1>(q.front());
		int depth = get<2>(q.front());
		q.pop();
		if(cy == destY && cx == destX) {
			return depth;
		}
		for(int k=0; k<4; ++k) {
			for(int l=1; l<=K; ++l) {
				int ny = cy + dy[k] * l;
				int nx = cx + dx[k] * l;
				if(inRange(ny, nx) && !isVisited[ny][nx] && canPassThrough(cy, cx, ny, nx)) {
					q.push(make_tuple(ny, nx, depth+1));	
					isVisited[ny][nx] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> K;	
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			cin >> gym[i][j];
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;
	cout << solve(y1-1, x1-1, y2-1, x2-1);
}
