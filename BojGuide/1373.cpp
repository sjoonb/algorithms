#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

string str;

int convert(string bin) {
	int ret = 0;
	for(int i=0; i<3; ++i)	
		ret += (bin[i] - '0') * pow(2, 2-i);
	return ret;
}

void solve() {
	int n = 3 - str.size() % 3;
	for(int i=0; i<n; ++i)
		str.insert(0, "0");
	for(int i=0; i<str.size(); i+=3)
		cout << convert(str.substr(i, i+3));
				
}

int main() {
	cin >> str;	
	solve();	
	return 0;
}
