#include <iostream>
using namespace std;

bool isBitSet(unsigned long long a, int b) {
	return (a & (1<<b)) > 0;
}

int bitCount(int x) {
	if(x==0) return 0;	
	return x%2 + bitCount(x/2);
}

int main() {
	for(int i=0; i<10; ++i) 
		cout << __builtin_ctz(i) << "\n";
		//cout << bitCount(i) << "\n";
}
