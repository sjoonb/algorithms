#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

int n, tr[100][100];
int dp[100][100];

void solve() {
	for(int i=1; i<n; ++i)
		for(int j=0; j<=i; ++j) {
			if(j==0) {
				tr[i][0] += tr[i-1][0];	
			} else if(j==i) {
				tr[i][j] += tr[i-1][j-1];	
			} else {
				tr[i][j] += max(tr[i-1][j], tr[i-1][j-1]);
			}
		}
}

int path(int y, int x) {
	if(y == n-1) return tr[y][x];
	int& ret = dp[y][x];
	if(ret != -1) return dp[y][x];
	return ret = tr[y][x] + max(path(y+1, x), path(y+1, x+1));
}

int main() {
	ifstream file("input.txt");
	stringstream cin;
	cin << file.rdbuf();
	file.close();
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n;
		for(int i=0; i<n; ++i)
			for(int j=0; j<=i; ++j)
				cin >> tr[i][j];
		memset(dp, -1, sizeof(dp));
		cout << path(0, 0) << "\n";
	}
	return 0;
}
