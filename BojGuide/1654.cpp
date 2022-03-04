#include <iostream>
using namespace std;

#define ll long long

int K, N;
int wires[100000];

int f(int x) {
	int ret = 0;
	for(int i=0; i<K; ++i)	
		ret += wires[i] / x;
	return ret;
}

int bisection() {
	ll lo = 0, hi = (1ll << 31); 	
	for(int iter=0; iter<100; ++iter) {
		ll mid = (lo + hi) / 2;	
		int fmid = f(mid);
		if(fmid >= N)
			lo = mid;
		else
			hi = mid;
	}
	return (lo + hi) / 2;
}

int main() {
	cin >> K >> N;	
	for(int i=0; i<K; ++i)
		cin >> wires[i];
	cout << bisection();
	return 0;
}
