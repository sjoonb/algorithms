#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return (a*b)/gcd(a, b);
}

int main() {
//	cout << gcd(3, 7) << "\n";
//	cout << lcm(3, 7);
	cout << -5%3;
	return 0;
}

