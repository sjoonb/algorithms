#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100;
unsigned char sieve[(MAX_N+7) / 8];

inline bool isPrime(int k) {
	return sieve[k/8] & (1 << (k%8));
}

inline void setComposite(int k) {
	sieve[k/8] &= ~(1 << (k % 8));
}

void eratosthenes(int n) {
	// on
	memset(sieve, 255, sizeof(sieve));	
	setComposite(0);
	setComposite(1);
	for(int i=2; i*i<=n; ++i)
		if(isPrime(i))
			for(int j=i*i; j<n; j+=i)
				setComposite(j);
}

int main() {
	int n = 100;
	eratosthenes(n);
	for(int i=0; i<n; ++i)
		if(isPrime(i))
			cout << i << "\n";
	return 0;
}
