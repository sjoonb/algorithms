#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxRect(vector<int>& fence, int n) {
	fence.push_back(0);
	vector<int> remaining;

	int rect=0;
	for(int idx=0; idx<fence.size(); ++idx) {
		while(!remaining.empty() && fence[remaining.top()] >= fence[idx]) {
			int j = remaining.top();
			remaining.pop();
			int width = (idx - remaining.top() -1);
		}
	}
	return rect;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n;
		cin >> n;
		vector<int> fence(n);
		for(int i=0; i<n; ++i)
			cin >> fence[i];
		cout << maxRect(fence, n) << "\n";
	}
}
