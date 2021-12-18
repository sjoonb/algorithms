#include <iostream>
#include <vector>
using namespace std;

int n, material[200], already[200];

int GCD(int a, int b) {
	if(b == 0) return a;
	return GCD(b, a%b);	
}

vector<int> solve() {
	int gcd = material[0];	
	for(int i=1; i<n; ++i) {
		gcd = GCD(gcd, material[i]);
	}
	for(int i=0; i<n; ++i)
		material[i] /= gcd;
	int mul = 1;
	while(true) {
		int i;
		for(i=0; i<n; ++i) {
			if(already[i] > material[i]*mul)
				break;
		}
		if(i==n) break;
		mul++;
	}
	vector<int> ret(n);
	for(int i=0; i<n; ++i)
		ret[i] = material[i]*mul - already[i];
	return ret;
}

int main() {
	int cases;	
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> material[i];
		for(int i=0; i<n; ++i)
			cin >> already[i];
		vector<int> ret = solve();
		for(int i=0; i<ret.size(); ++i)
			cout << ret[i] << " ";
		cout << "\n";
	}
}
