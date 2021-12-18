#include <iostream>
#include <vector>
using namespace std;

int cache[19683];

int bijection(const vector<string>& board) {
	int ret = 0;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			ret *= 3;  	
			if(board[i][j] == 'x') ++ret;
			else if(board[i][j] == 'o') ret += 2;
		}
	return ret;
}

bool isFinished(const vector<string>& board, char turn) {
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			if(board[i][j] != turn) break;
			if(j==2) return true;
		}
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			if(board[j][i] != turn) break;
			if(j==2) return true;
		}
	for(int i=0; i<3; ++i) {
		if(board[i][i] != turn) break;
		if(i==2) return true;	
	}
	for(int i=0; i<3; ++i) {
		if(board[i][2-i] != turn) break;
		if(i==2) return true;	
	}
	return false;	
}

int canWin(vector<string>& board, char turn) {
	if(isFinished(board, 'o' + 'x' - turn)) return -1;
	int& ret = cache[bijection(board)];
	if(ret != -2) return ret;
	int minValue = 2;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			if(board[i][j] == '.') {
				board[i][j] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));	
				board[i][j] = '.';
			}
		}
	if(minValue == 2 || minValue == 0) return ret = 0;
	return ret = -minValue;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int cnt = 0;
		vector<string> board;
		string temp;
		for(int i=0; i<19683; ++i)
			cache[i] = -2;
		for(int i=0; i<3; ++i) {
			cin >> temp;
			for(int j=0; j<3; ++j)
				if(temp[j] != '.')
					cnt++;
			board.push_back(temp);
		}
		char start = (cnt % 2 == 1) ? 'o' : 'x';
		int ret = canWin(board, start);
		if(ret == 1) cout << start;
		else if(ret == 0) cout << "TIE";
		else cout << (char)('o' + 'x' - start);
	}
	return 0;
}
