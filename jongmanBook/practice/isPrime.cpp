#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 101;

int n;
bool isPrimeArr[MAX];
int minFactor[MAX];

bool isPrime(int n) {
	if(n <= 1) return false;
	if(n == 2) return true;
	if(n%2 == 0) return false;
	int sqrtn = sqrt(n);
	for(int i=3; i<=sqrtn; ++i) {
		if(n%i == 0)
			return false;	
	}
	return true;
}

vector<int> factorSimple(int n) {
	vector<int> ret;
	int sqrtn = int(sqrt(n));
	for(int div=2; div<=sqrtn; ++div) {
		while(n%div == 0) {
			n /= div;
			ret.push_back(div);		
		}
	}
	if(n>1) ret.push_back(n);
	return ret;
}

void eratosthenes() {
	memset(isPrimeArr, 1, sizeof(isPrimeArr));	
	isPrimeArr[0] = isPrimeArr[1] = false;
	int sqrtn = int(sqrt(n));
	for(int i=2; i<= sqrtn; ++i)
		if(isPrimeArr[i])
			for(int j=i*i; j<=n; j+=i)
				isPrimeArr[j] = false;
}

void eratosthenes2() {
	minFactor[0] = minFactor[1] = -1;	
	for(int i=2; i<=n; ++i)
		minFactor[i] = i;
	int sqrtn = int(sqrt(n));
}

int main() {
	n = 100;
	eratosthenes();
	for(int i=1; i<=n; ++i)
		if(isPrimeArr[i])
			cout << i << " is prime num\n";
}
