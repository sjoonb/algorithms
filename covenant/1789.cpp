#include <iostream>
#include <cmath>
using namespace std;

long long S;

int sumOfSeq() {
	return (-1 + sqrt((long long)1 + 8*S)) / 2;
}

int main() {
	cin >> S;
	cout << sumOfSeq();
}
