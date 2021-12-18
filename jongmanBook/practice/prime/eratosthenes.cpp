#include <iostream>
#include <cmath>
using namespace std;

const int TM = 1e7;
int minFactor[TM+1];
int minFactorPower[TM+1];
int factors[TM+1];

void eratosthenes() {
	minFactor[0] = minFactor[1] = -1;
	for(int i=2; i<=TM; ++i)
		minFactor[i] = i;
	for(int i=2; i*i <= TM; ++i) {
		if(minFactor[i] == i) {
			for(int j=i*i; j<=TM; j+=i)
				if(minFactor[j] == j)
					minFactor[j] = i;
		}
	}
}

void getFactorsSmart() {
	factors[1] = 1;
	for(int n=2; n<=TM; ++n) {
		if(minFactor[n] == n) {
			minFactorPower[n] = 1;
			factors[n] = 2;
		} else {
			int p = minFactor[n];
		}
	}
}

int main() {
	getFactorsSmart();	
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n, lo, hi, ret=0;	
		cin >> n >> lo >> hi;
		for(int j=lo; j<=hi; ++j)
			if(factors[j] == n)
				++ret;
		cout << ret << endl;
	}
}
