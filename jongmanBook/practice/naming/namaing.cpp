#include <iostream>
using namespace std;

void solve(const string& str) {
	int n = str.size();
	for(int i=1; i<=n; ++i) {
		int j;		
		for(j=0; j<i; ++j) {
			if(str[j] != str[n-i+j])
				break;
		}
		if(j==i)
			cout << j << " ";
	}
}

int main() {
	string dad, mom;	
	cin >> dad >> mom;

	string str = dad + mom;
	solve(str);
}
