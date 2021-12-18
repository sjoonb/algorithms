#include <iostream>
using namespace std;

const int MOD = 1000000007;

string e, digits;
int n, m;


void generate(string price, bool taken[15]) {
	if(price.size() == n) {
		if(price < e)
			cout << price << endl;	
		return;
	}
	for(int i=0; i<n; ++i)
		if(!taken[i] && (i==0 || digits[i-1] != digits[i] || taken[i-1])) {
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> e >> m;
		n = e.size();
		digits = e;
		sort(digits.begin(), digits.end());
		bool taken[15] = { false, };
		generate("", taken);
	}
	return 0;	
}
