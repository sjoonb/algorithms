#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> board;
vector<vector<bool> > isVisited;
vector<int> ret;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < N)
		return true;
	return false;	
}

int dfs(int y, int x) {
	int ret = 1;
	for(int k=0; k<4; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if(inRange(ny, nx) && !isVisited[ny][nx] && board[ny][nx] == '1') {
			isVisited[ny][nx] = true;
			ret += dfs(ny, nx);
		}
	}
	return ret;
}

void solve() {
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if(!isVisited[i][j] && board[i][j] == '1') {
				isVisited[i][j] = true;
				ret.push_back(dfs(i, j));
			}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for(int i=0; i<ret.size(); ++i)
		cout << ret[i] << "\n";
}

int main() {
	cin >> N;
	board = vector<string>(N);
	isVisited = vector<vector<bool> >(N, vector<bool>(N, false));
	for(int i=0; i<N; ++i) {
		string str;
		cin >> str;
		board[i] = str;
	}
	solve();
	return 0;
}
