#include <iostream>
using namespace std;

int inverseElement(int a, int m) {
	int x;
	for(int i=1; i<m; ++i) {
		if((a*i) % m == 1) {
			x = i;
		}
	}
	return x;
}

int main() {	
	cout << inverseElement(2, 3);
}
