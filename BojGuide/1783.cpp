#include <iostream>
using namespace std;

int N, M;

int solve() {
	if(N == 1) {
		return 1;	
	} else if(N == 2) {
		if(M < 3)
			return 1;
		else if(M < 5)
			return 2;
		else if(M < 7)
			return 3;
		else 
			return 4;
	} else {
		if(M < 2)
			return 1;
		else if(M < 3)
			return 2;
		else if(M < 4)
			return 3;
		else if(M < 7)
			return 4;
		else
			return 5 + (M - 7);
	}
	return -1;
}

int main() {
	cin >> N >> M;
	cout << solve();
	return 0;
}
