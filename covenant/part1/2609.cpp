#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if(a==0)
		return b;
	else
		return GCD(b%a, a);
}

int main() {
	int n, m;
	cin >> n >> m;
	int gcd = GCD(n, m);
	int lcm = n * m / gcd;
	cout << gcd << "\n";
	cout << lcm;
}
