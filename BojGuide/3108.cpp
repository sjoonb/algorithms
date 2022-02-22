#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool board[1001][1001];


int draw(int x1, int y1, int x2, int y2) {
	int ret = 1;
	int i, j;
	i = y1;
	for(j = x1; j < x2; ++j) {
		if(board[i][j])
			ret = 0;
		board[i][j] = true;
	}
	for(; i < y2; ++i) {
		if(board[i][j])
			ret = 0;
		board[i][j] = true;
	}
	for(; j > x1; --j) {
		if(board[i][j])
			ret = 0;
		board[i][j] = true;
	}
	for(; i > y1; --i) {
		if(board[i][j])
			ret = 0;
		board[i][j] = true;
	}
	return ret;
}

int main() {
	int ret = 0;
	cin >> N;
	for(int i=0; i<N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;	
		x1 += 500;
		y1 += 500;
		x2 += 500;
		y2 += 500;
		ret += draw(x1, y1, x2, y2);
	}
	if(board[500][500])
		ret--;
	cout << ret;
	return 0;	
}
