#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int cache[50][50];
vector<int> board;

int solve(const vector<int>& board) {
	if(board.size() == 0) return 0;
	int ret = -INF;
	if(board.size() >= 2) {
		ret = max(ret, -solve(vector<int>(board.begin()+2, board.end())));
		ret = max(ret, -solve(vector<int>(board.begin(), board.end()-2)));
	}
	ret = max(ret, board.front() - solve(vector<int>(board.begin()+1, board.end())));
	ret = max(ret, board.back() - solve(vector<int>(board.begin(), board.end()-1)));
	return ret;
}

int play(int left, int right) {
	if(left > right) return 0;
	int& ret = cache[left][right];
	if(ret != -INF) return ret;
	ret = max(board[left] - play(left+1, right), board[right] - play(left, right-1));
	if(right - left + 1 >= 2) {
		ret = max(ret, -play(left+2, right));
		ret = max(ret, -play(left, right-2));
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int n;
		cin >> n;
		board = vector<int>(n);
		for(int i=0; i<n; ++i)
			cin >> board[i];
		//cout << solve(board) << "\n";	
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cache[i][j] = -INF;
		cout << play(0, n-1) << "\n";
	}
}
