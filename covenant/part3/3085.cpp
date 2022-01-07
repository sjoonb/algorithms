#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> board;

int check(int idx, bool horizontal) {
	int ret = 1;
	int cnt = 1;
	if(horizontal) {
		for(int k=0; k<N-1; ++k) {
			if(board[idx][k] == board[idx][k+1]) {
				cnt++;
			} else {
				ret = max(ret, cnt);
				cnt=1;
			}
		}
		ret = max(ret, cnt);
	} else {
		for(int k=0; k<N-1; ++k) {
			if(board[k][idx] == board[k+1][idx]) {
				cnt++;
			} else {
				ret = max(ret, cnt);
				cnt=1;
			}
		}
		ret = max(ret, cnt);
	}
	return ret;	
}

void swap(int i, int j, bool horizontal) {
	int temp = board[i][j];
	if(horizontal) {
		board[i][j] = board[i][j+1];
		board[i][j+1] = temp;
	} else {
		board[i][j] = board[i+1][j];
		board[i+1][j] = temp;
	}
}

int bruteForce() {
	int ret=1;
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j) {
			if(j+1 < N) {
				swap(i, j, true);
				ret = max(ret, check(j, false));
				ret = max(ret, check(j+1, false));
				ret = max(ret, check(i, true);
				swap(i, j, true);
			}
			if(i+1 < N) {
				swap(i, j, false);
				ret = max(ret, check(i, true));
				ret = max(ret, check(i+1, true));
				ret = max(ret, check(j, false));
				swap(i, j, false);
			}
		}

	return ret;	
}

int main() {
	cin >> N;
	board = vector<string>(N);
	for(int i=0; i<N; ++i) {
		cin >> board[i];
	}
	
	cout << bruteForce();
}
