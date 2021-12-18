#include <iostream>
#include <limits>
using namespace std;

int main() {
	unsigned long long i = (1ll << 63) | ((1ull << 63) - 1);
	unsigned long long j = numeric_limits<unsigned long long>::max();
	long long k = numeric_limits<long long>::max();


	cout << i << endl;
	cout << j << endl;
	cout << k;

	//cout << sizeof(int);
}
