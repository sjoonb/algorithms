#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> board;
bool dp[10][5][5];

bool inRange(int y, int x) {
	return y>=0 && y<5 && x>=0 && x<5;	
}

bool hasWord(int cy, int cx, const string& word) {
	if(word.size() == 0) return true;
	for(int k=0; k<8; ++k) {
		int ny = cy + dy[k];
		int nx = cx + dx[k];
		if(inRange(ny, nx) && board[ny][nx] == word[0] && dp[word.size()-1][ny][nx])
			if(hasWord(ny, nx, word.substr(1)))
				return true;
	}
	return dp[word.size()][cy][cx] = false;
}

string boggle(const string& word) {
	memset(dp, true, sizeof(dp));
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j) 
			if(board[i][j] == word[0]) {
				if(hasWord(i, j, word.substr(1)))
					return "YES";
			}
	return "NO";	
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		board.resize(5);
		for(int i=0; i<5; ++i)
			cin >> board[i];
		int n;
		cin >> n;
		for(int i=0; i<n; ++i) {
			string word;
			cin >> word;
			cout << word << " " << boggle(word) << "\n";
		}
			
	}
}

