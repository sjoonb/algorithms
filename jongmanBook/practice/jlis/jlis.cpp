#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> A, B;
int n, m, dp[101][101];
const long long NEGINF = numeric_limits<long long>::min();

int jlis(int idxA, int idxB) {
	int& ret = dp[idxA+1][idxB+1]; 
	if(ret != -1) return ret;

	ret = 0;

	long long maxA = (idxA == -1) ? NEGINF : A[idxA];
	long long maxB = (idxB == -1) ? NEGINF : B[idxB];
	long long maxElement = max(maxA, maxB);

	for(int i=idxA+1; i<n; ++i)
		if(A[i] > maxElement) 
			ret = max(ret, jlis(i, idxB) + 1);

	for(int i=idxB+1; i<m; ++i)
		if(B[i] > maxElement) 
			ret = max(ret, jlis(idxA, i) + 1);

	return ret;	
}

int main() {
//	fstream file("input.txt");
//	stringstream cin;
//	cin << file.rdbuf();
//	file.close();
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> m;
		A = vector<int>(n);
		B = vector<int>(m);
		for(int i=0; i<n; ++i) cin >> A[i];
		for(int i=0; i<m; ++i) cin >> B[i];
		memset(dp, -1, sizeof(dp));
		cout << jlis(-1, -1) << "\n";
	}
	return 0;	
}
