#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> isPrime(10001, true);

void eratosthenes() {
	isPrime[1] = false;	
	for(int i=2; i*i<=10000; ++i) {
		if(isPrime[i]) {
			for(int j=i*2; j<=10000; j+=i)
				isPrime[j] = false;
		}
	}
}

int main() {
	eratosthenes();	
	int m, n;
	cin >> m >> n;
	int sum = 0;
	int _min;
	for(int i=m; i<=n; ++i) {
		if(isPrime[i]) {
			if(sum == 0)
				_min = i;
			sum += i;
		}
	}
	(sum == 0) ? cout << -1 : cout << sum << endl << _min;
}
