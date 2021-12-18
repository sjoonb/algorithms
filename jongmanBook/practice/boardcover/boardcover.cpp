#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// fill, unfill, if fullfill return 1 

int h, w;
vector<string> board;

const int blockTypes[4][3][2] = { {{0, 0}, {1, 0}, {1, -1}},
								  {{0, 0}, {1, 0}, {0, 1}},
								  {{0, 0}, {0, 1}, {1, 1}},
								  {{0, 0}, {1, 0}, {1, 1}} };

bool inRange(int y, int x) {
	return y >= 0 && y < h && x >= 0 && x < w;
}

bool canFill(int block, int cy, int cx) {
	for(int i=0; i<2; ++i) {
		int ny = cy + blockTypes[block][i+1][0];
		int nx = cx + blockTypes[block][i+1][1];
		if(!inRange(ny, nx) || board[ny][nx] == '#')
			return false;
	}
	return true;	
}

void fill(int block, int cy, int cx, char ch) {
	board[cy][cx] = ch;
	for(int i=0; i<2; ++i) {
		int ny = cy + blockTypes[block][i+1][0];
		int nx = cx + blockTypes[block][i+1][1];
		board[ny][nx] = ch;
	}
}

int boardcover() {
	int y=-1, x=-1;
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j)
			if(board[i][j] == '.') {
				y = i; x = j;	
				break;
			}
		if(y!=-1)
			break;
	}
	if(y==-1) return 1;	
	int ret=0;
	for(int block=0; block<4; ++block) {
		if(canFill(block, y, x)) {
			fill(block, y, x, '#');
			ret += boardcover();
			fill(block, y, x, '.');
		}
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> h >> w;
		board.resize(h);
		for(int i=0; i<h; ++i) {
			cin >> board[i];
		}
		cout << boardcover() << "\n";
	}
	return 0;	
}
