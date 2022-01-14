#include <iostream>
#include <algorithm>
using namespace std;

int A;
long long B;
const int INF = 1e9;

int dfs(long long num, int depth=0) {
	if(num >= B) {
		return (num == B) ? depth : INF;
	}
	int method1 = dfs(num * 2, depth+1);
	int method2 = dfs(num * 10 + 1, depth+1);
	return min(method1, method2);
}

int main() {
	cin >> A >> B;
	int ret = dfs(A);
	if(ret != INF)
		cout << ret+1;
	else
		cout << -1;
}
