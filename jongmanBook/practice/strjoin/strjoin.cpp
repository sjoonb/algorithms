#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> arr;

int strjoin() {
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<n; ++i)
		pq.push(arr[i]);
	int ret = 0;
	while(pq.size() > 1) {
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n;	
		arr = vector<int>(n);
		for(int i=0; i<n; ++i)
			cin >> arr[i];
		cout << strjoin() << "\n";
	}
	return 0;	
}
