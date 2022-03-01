#include <iostream>
#include <cmath>
using namespace std;

string N;
int B;

int convert(string N, int B) {
	int ret = 0, product = 0;
	for(int i=N.size()-1; i>=0; --i) {
		ret += (N[i] <= '9' ? N[i] - '0' : N[i] - 'A' + 10) * pow(B, product);	
		product++;
	}
	return ret;
}

int main() {
	cin >> N >> B;
	cout << convert(N, B);
	return 0;
}
