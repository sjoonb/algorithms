#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n < 2) {
		printf("%d", n);
		exit(0);
	}
	int a = 0;
	int b = 1;
	for(int i=2; i<=n; ++i) {
		int c = a + b;
		a = b;
		b = c;
	}
	printf("%d", b);	
}
