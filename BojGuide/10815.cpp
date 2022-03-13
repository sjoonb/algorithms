#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> bst;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for(int i=0; i<N; ++i) {
		int num;
		cin >> num;
		bst.insert(num);
	}
	cin >> M;
	for(int i=0; i<M; ++i) {
		int num;
		cin >> num;
		auto it = bst.find(num);
		cout << (it != bst.end() ? 1 : 0) << " ";
	}
	return 0;
}

