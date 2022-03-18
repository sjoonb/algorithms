#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char> > board;

void dnq(int n, int ci, int cj) {
	if(n == 1) {
		board[ci][cj] = '*';
		return;
	}
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			if(i == 1 && j == 1)
				continue;
			dnq(n/3, ci + i * (n/3), cj + j * (n/3));
		}
}

void draw() {
	for(int i=0; i<N; ++i) {
	   for(int j=0; j<N; ++j)
		   cout << board[i][j];
	   cout << "\n";
   }
}

int main() {
	cin >> N;
	board = vector<vector<char> >(N, vector<char>(N, ' '));
	dnq(N, 0, 0);
	draw();
	return 0;
}
