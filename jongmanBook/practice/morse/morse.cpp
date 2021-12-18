#include <iostream>
#include <cstring>
using namespace std;

const int M = 1e9 + 100;
int n, m, k, bino[201][201];

void morse(int a, int b, string signal) {
	if(k<0)
		return;
	if(a==0 && b==0) {
		if(k==0)
			cout << signal << "\n";
		k--;
		return;
	}
	if(a>0) morse(a-1, b, signal + "-");
	if(b>0) morse(a, b-1, signal + "o");
}

void calcBino() {
	memset(bino, 0, sizeof(bino));
	for(int i=0; i<=200; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for(int j=1; j<i; ++j)
			bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
	}
}

void generate1(int n, int m, string s) {
	if(k<0)
		return;
	if(n==0 && m==0) {
		if(k==0) cout << s;
		k--;
		return;
	}
	if(bino[n+m][n] <= k) {
		k -= bino[n+m][n];
		return;
	}
	if(n>0) generate1(n-1, m, s+"-");
	if(m>0) generate1(n, m-1, s+"o");
}

string kth(int n, int m, int skip) {
	if(n==0) { return string(m, 'o');
	if(skip < bino[n+m-1][n-1])
		return "-" + kth(n-1, m, skip);
	return "o" + kth(n, m-1, skip - bino[n+m-1][n-1]);
}

int main() {
	int cases;
	cin >> cases;
	calcBino();
	for(int c=0; c<cases; ++c) {
		cin >> n >> m >> k;
		k--;
		cout << kth(n, m, k) << "\n";
//		generate1(n, m, "");
//		cout << "\n";
	}
	return 0;
}
