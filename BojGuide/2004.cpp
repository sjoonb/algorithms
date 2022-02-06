#include <iostream>
using namespace std;

long long count(int num) {
	long long cnt = 0;
	for(long long div = 5; div<=num; div*=5) {
		cnt += num / div;	
	}
	return cnt;	
}

int main() {
	long long N, M;
	cin >> N >> M;
	long long ret = count(N) - count(M) - count(N-M);
	cout << ret;
	return 0;
}
