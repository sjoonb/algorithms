#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> isPrime(1001, true);

void eratosthenes() {
	isPrime[1] = false;
	for(int i=2; i*i<=1000; ++i) {
		if(!isPrime[i])
			continue;
		int j=i*2;
		while(j <= 1000) {
			isPrime[j] = false;
			j += i;
		}
	}
}

int main() {
	eratosthenes();	
	int n;
	cin >> n;
	int cnt=0;
	for(int i=0; i<n; ++i) {
		int num;
		cin >> num;
		if(isPrime[num])
			cnt++;
	}
	cout << cnt;
}
