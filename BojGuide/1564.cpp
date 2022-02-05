#include <iostream>
using namespace std;

int N;

// 관건은 0을 6개를 빼줘도 5개는 남도록, 즉 11개는 유지해야 하는 것 같다. 
//

long long solve() {
	long long ret = 1;
	for(long long i=1; i<=N; ++i)	{
		ret *= i;	
		while(ret % 10 == 0)
			ret /= 10;
		ret %= (long long)1e12;
	}
	return ret %= (long long)1e5;
}

int main() {
	cin >> N;
	printf("%05lld", solve());
	return 0;
}
