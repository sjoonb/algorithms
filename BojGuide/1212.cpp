#include <iostream>
using namespace std;

string octal;

int oct_to_bin(int oct) {
	int ret = 0, product = 1;
	while(oct != 0) {
		ret += oct % 2 * product;
		oct /= 2;
		product *= 10;
	}
	return ret;
}

void convert() {
	cout << oct_to_bin(octal[0] - '0');
	for(int i=1; i<octal.size(); ++i) {
		string bin = to_string(oct_to_bin(octal[i] - '0'));	
		bin.insert(0, string(3 - bin.size(), '0'));
		cout << bin;
	}
}

int main() {
	cin >> octal;
	convert();
	return 0;
}
