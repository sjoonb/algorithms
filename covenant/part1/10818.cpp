#include <iostream>
using namespace std;

void solve(int n) {
	int num;
	int _min = 1e6 + 1;
	int _max = -1e6 - 1;
	for(int i=0; i<n; ++i) {
		cin >> num;
		if(num < _min) _min = num;
		if(num > _max) _max = num;
	}
	printf("%d %d", _min, _max);
}

int main() {
	int n;
	cin >> n;
	solve(n);
}
