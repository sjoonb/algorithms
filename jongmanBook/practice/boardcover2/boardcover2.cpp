#include <iostream>
#include <vector>
using namespace std;


vector<vector<pair<int, int> > > rotations;
vector<vector<int> > board;
int h, w, r, c, best, blockSize;

bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
	bool ok = true;
	for(int i=0; i<block.size(); ++i) {
		int ny = y + block[i].first;	
		int nx = x + block[i].second;	
		if(ny < 0 || ny >= h || nx < 0 || nx >= w)
			ok = false;
		else if((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int heuristic(int placed) {
	int cnt=0;
	for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
			cnt += !(board[i][j]) ? 1 : 0;
	return (cnt/blockSize) + placed <= best;
}

void search(int placed) {
	if(heuristic(placed))
		return;
	int y=-1, x=-1;
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j) {
			if(board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}
	if(y == -1) {
		best = max(best, placed);
		return;
	}
	for(int i=0; i<rotations.size(); ++i) {
		if(set(y, x, rotations[i], 1))
			search(placed+1);
		set(y, x, rotations[i], -1);
	}
	board[y][x] = 1;
	search(placed);
	board[y][x] = 0;
}

vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for(int i=0; i<arr.size(); ++i)
		for(int j=0; j<arr[0].size(); ++j)
			ret[j][arr.size()-i-1] = arr[i][j];
	return ret;
}

void generateRotations(vector<string> block) {
	rotations.clear();	
	rotations.resize(4);
	for(int rot=0; rot<4; ++rot) {
		int originY = -1, originX = -1;
		for(int i=0; i<block.size(); ++i)
			for(int j=0; j<block[i].size(); ++j)
				if(block[i][j] == '#') {
					if(originY == -1) {
						originY = i;
						originX = j;
					}
					rotations[rot].emplace_back(i-originY, j-originX);
				}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}

int main() {
	int cases;	
	cin >> cases;
	for(int cs=0; cs<cases; ++cs) {
		cin >> h >> w >> r >> c;
		board = vector<vector<int> >(h, vector<int>(w, 0));
		for(int i=0; i<h; ++i) {
			string str;
			cin >> str;	
			for(int j=0; j<str.size(); ++j)
				board[i][j] = (str[j] == '#' ? 1 : 0);
		}
		vector<string> block(r);
		for(int i=0; i<r; ++i) {
			cin >> block[i];
		}
	  	generateRotations(block);
		best = 0;
	  	search(0);
		cout << best << "\n";
	}
	return 0;
}
