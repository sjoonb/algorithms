#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char dp[1<<25];
const int blockTypes[6][3][2] = { {{0, 0}, {0, 0}, {1, 0}}, // l 
								  {{0, 0}, {0, 0}, {0, 1}}, // ㅡ
								  {{0, 0}, {1, 0}, {1, -1}},
								  {{0, 0}, {0, 1}, {1, 1}},
								  {{0, 0}, {1, 0}, {0, 1}},
								  {{0, 0}, {1, 0}, {1, 1}} };

int bijection(const vector<string>& board) {
	int ret = 0;
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j) {
			// 5*i + j
			if(board[i][j] == '#') {
				ret |= (1 << (i*5 +j));	
			}
		}
	return ret;
}

bool canFill(const vector<string>& board, int block, int y, int x) {
	for(int i=0; i<3; ++i) {
		int cy = y + blockTypes[block][i][0];
		int cx = x + blockTypes[block][i][1];
		if(cy >= 0 && cy < 5 && cx >= 0 && cx < 5 && board[cy][cx] != '#')
			continue;
		else
			return false;
	}
	return true;
}

void fill(vector<string>& board, int block, int y, int x, char ch) {
	for(int i=0; i<3; ++i) {
		int cy = y + blockTypes[block][i][0];
		int cx = x + blockTypes[block][i][1];
		board[cy][cx] = ch;
	}
}

int canWin(vector<string>& board) {
	char& ret = dp[bijection(board)];
	if(ret != -1) return ret;
	ret = false;
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			if(board[i][j] == '.')
				for(int block=0; block<6; ++block) {
					if(canFill(board, block, i, j)) {
						fill(board, block, i, j, '#');
						if(!canWin(board))
							return true;
						fill(board, block, i, j, '.');
					}
				}
	return ret;	
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		vector<string> board(5);
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<5; ++i)
			cin >> board[i];
		canWin(board) ? cout << "WINNING" : cout << "LOSING";
//		if(canWin(board))
//			cout << "WINNING";
//		else
//			cout << "LOSING";
		cout << "\n";
	}
	return 0;	
}
