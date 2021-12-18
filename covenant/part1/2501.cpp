#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k) {
	int div = 1;
	int kth = 0;
	while(div <= n) {
		if(n % div == 0) kth++;	
		if(kth == k)
			return div;
		div++;
	}
	return 0;
}


int main() {
	int n, k;
	cin >> n >> k;
	int ret = solve(n, k);
	printf("%d", ret);
}
