#include <iostream>
#include <chrono>
using namespace std;

int dp[100][100];


int call1;
int call2;

int bino(int n, int r) {
	call1++;
	if(r==0 || n==r) return 1;
	return bino(n-1, r-1) + bino(n-1, r);
}

int binoDP(int n, int r) {
	call2++;
	if(r==0 || n==r) return 1;	
	if(dp[n][r] != -1)
		return dp[n][r];
	return dp[n][r] = binoDP(n-1, r-1) + binoDP(n-1, r);
}

int main() {
	chrono::system_clock::time_point start = chrono::system_clock::now();
	cout << bino(25, 12) << "\n";
	chrono::duration<double> sec = chrono::system_clock::now() - start;
	cout << sec.count() << "\n";
	cout << "call: " << call1 << "\n";

	start = chrono::system_clock::now();
	memset(dp, -1, sizeof(dp));
	cout << binoDP(25, 12) << "\n";	
	sec = chrono::system_clock::now() - start;
	cout << sec.count() << "\n";
	cout << "call: " << call2 << "\n";

	return 0;
}
