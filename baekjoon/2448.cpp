#include <iostream>
#include <vector>
using namespace std;

int N;

vector<string> board;

void dnq(int n, int ci, int cj) {
	if(n == 3) {
		board[ci][cj + 2] = '*';	
		board[ci+1][cj+1] = '*';	
		board[ci+1][cj+3] = '*';	
		for(int i=0; i<5; ++i)
			board[ci+2][cj+i] = '*';
		return;
	}
	dnq(n/2, ci, cj + n/2); 
	dnq(n/2, ci + n/2, cj); 
	dnq(n/2, ci + n/2, cj + n); 
}

void draw() {
	for(int i=0; i<N; ++i) {
		for(int j=0; j<2*N; ++j) 
			cout << board[i][j];
		cout << "\n";
	}
}

int main() {
	cin >> N;
	board = vector<string>(N, string(N*2, ' '));
	dnq(N, 0, 0);
	draw();
	return 0;
}
