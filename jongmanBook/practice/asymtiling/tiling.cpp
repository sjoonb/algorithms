#include <iostream>
using namespace std;

int tiling(int width) {
	if(width <= 1) return 1;
	return tiling(width-2) + tiling(width-1);	
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int n;
		cin >> n;
		cout << tiling(n) << "\n";	
	}
	return 0;	
}
