#include <iostream>
#include <cmath>
using namespace std;

int bin_to_oct(int bin) {
	int ret = 0, square = 0;
	while(bin > 0) {
		ret += bin % 10 * pow(2, square++);
		bin /= 10;
	}
	return ret;
}

string convert(string binary) {	
	string ret;
	for(int i=0; i<binary.size(); i+=3) {
		int bin = stoi(binary.substr(i, 3));
		int hex = bin_to_oct(bin);
		cout << hex;
	}
	return ret;
}

int main() {
	string binary;	
	cin >> binary;	
	while(binary.size() % 3 != 0) {
		binary.insert(0, "0");		
	}
	cout << convert(binary);
	return 0;
}
