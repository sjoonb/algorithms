#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int convert(int binary) {
	int square = 0;
	int ret = 0;
	while(binary > 0) {
		int bit = binary % 10;
		ret += bit * pow(2, square++);
		binary /= 10;
	}
	return ret;	
}

void solve(int num) {
	if(num == 0) {
		cout << 0;
		return;
	}

	vector<int> octal;
	while(num > 0) {
		int binary = num % 1000;
		octal.push_back(convert(binary));
		num /= 1000;	
	}
	reverse(octal.begin(), octal.end());
	for(int i=0; i<octal.size(); ++i)
		cout << octal[i];
}

int main() {
	int num;
	cin >> num;	
	solve(num);	
	return 0;
}
