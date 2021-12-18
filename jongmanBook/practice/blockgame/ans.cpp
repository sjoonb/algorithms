#include <iostream>
#include <vector>
using namespace std;

vector<int> moves;
char cache[1<<25];

int cell(int y, int x) {
	return (1 << (y*5 + x));
}

void precalc() {
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j) {
			vector<int> cells;
			for(int dy=0; dy<2; ++dy)
				for(int dx=0; dx<2; ++dx)
					cells.push_back(cell(i+dy, j+dx));
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for(int i=0; i<4; ++i)
				moves.push_back(square - cells[i]);
		}
	for(int i=0; i<5; ++i)
		for(int j=0; j<4; ++j) {
			moves.push_back(cell(i, j) + cell(i, j+1));
			moves.push_back(cell(j, i) + cell(j+1, i));
		}
}

char play(int board) {
	char& ret = cache[board];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i=0; i<moves.size(); ++i) 
		if((moves[i]&board) == 0)
			if(!play(board | moves[i])) {
				ret = 1;
				break;
			}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	precalc();
	for(int c=0; c<cases; ++c) {
		memset(cache, -1, sizeof(cache));
		int board = 0;
		for(int i=0; i<5; ++i) 
			for(int j=0; j<5; ++j) {
				char ch;
				cin >> ch;
				if(ch == '#')
					board += cell(i, j);
			}
		if(play(board))
			cout << "WINNING\n";
		else
			cout << "LOSING\n";
	}
	return 0;
}
