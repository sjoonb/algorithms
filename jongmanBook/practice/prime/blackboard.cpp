#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[100]; 

void eratosthenes(int n) {	
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i*i<=n; ++i) {
		if(isPrime[i])	
			for(int j=i*i; j<n; j+=i)
				isPrime[j] = false;
	}
}

int main() {
	memset(isPrime, true, sizeof(isPrime));
	eratosthenes(100);
	for(int i=0; i<100; ++i)
		if(isPrime[i])
			cout << i << "\n";
}
