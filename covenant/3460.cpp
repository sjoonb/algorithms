#include <iostream>
#include <cmath>
using namespace std;

void solve(int n) {
	for(int i=0; i<20; ++i) {
		if(n & (1 << i))
			printf("%d ", i);
	}
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n;
		cin >> n;
		solve(n);
		printf("\n");
	}
}
