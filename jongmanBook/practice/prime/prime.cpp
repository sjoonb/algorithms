#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int dp[1000];
int n;
bool isPrime[101];

//bool isPrime(int n) {
//	int& ret = dp[n];
//	if(ret != -1) return ret;
//	if(n <= 1) return ret = false;
//	if(n == 2) return ret = true;
//	if(n%2 == 0) return ret = false;
//	int sqrtn = int(sqrt(n));
//	for(int i=3; i<=sqrtn; i+=2)
//		if(n%i == 0) return ret = false;
//	return ret = true;
//}

vector<int> factorSimple(int n) {
	vector<int> ret;
	int sqrtn = int(sqrt(n));	
	for(int div=2; div <= sqrtn; ++div)
		while(n%div == 0) {
			n /= div;
			ret.push_back(div);
		}
	if(n > 1) ret.push_back(n);
	return ret;
}

void eratosthenes() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(n));
	for(int i=2; i<=sqrtn; ++i) {
		if(isPrime[i])
			for(int j=i*i; j<=n; j+=i)
				isPrime[j] = false;
	}
}

int main() {
//	vector<int> ret;
//	for(int i=0; i<100; ++i) {
//		cout << "Case: " << i << "\n";
//		ret = factorSimple(i);
//		for(int j=0; j<ret.size(); ++j)
//			cout << ret[j] << " ";
//		cout << "\n";
//	}
	n = 100;
	eratosthenes();
	for(int i=0; i<n; ++i)
		if(isPrime[i])
			cout << i << "\n";
}




