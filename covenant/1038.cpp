#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long> res;

void dfs(int src, long long total, int depth) {
	if(depth == 0) {
		res.push_back(total);	
		return;
	}
	for(int i=src; i>=0; --i)
		dfs(i-1, total+(long long) i * pow(10, depth-1), depth-1);
}

int main() {
	for(int i=1; i<=10; ++i)
		dfs(9, 0, i);
	sort(res.begin(), res.end());
	int N;
	cin >> N;
	if(N < res.size())
		cout << res[N];
	else
		cout << -1;
}
