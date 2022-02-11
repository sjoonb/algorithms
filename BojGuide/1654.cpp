#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> wires;

int f(int x) {
	int ret = 0;	
	for(int i=0; i<K; ++i)
		ret += (wires[i] / x);
	return ret;
}

int bisection(long long lo, long long hi) {
	for(int i=0; i<100; ++i) {
		int mid = (lo + hi) / 2;
		int fmid = f(mid);
		if(fmid < N)
			hi = mid;
		else if(fmid >= N)
			lo = mid;
	}
	return (lo + hi) / 2;
}

int main() {
	cin >> K >> N;
	wires = vector<int>(K);
	for(int i=0; i<K; ++i)
		cin >> wires[i];
	cout << bisection(1, (unsigned int) 1 << 31);
	return 0;	
}
