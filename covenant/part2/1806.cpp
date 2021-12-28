#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> seq;

int solve() {
	int l, r, dist, sum;
	l = r = dist = sum = 0;
	int _min = 1e5;
	while(r < seq.size()) {
		sum += seq[r];	
		dist += 1;
		while(l <= r && sum >= s) {
			_min = min(_min, dist);
			sum -= seq[l];
			dist -= 1;
			l += 1;
		}
		r += 1;
	}
	return (_min == 1e5) ? 0 : _min;
}

int main() {
	cin >> n >> s;
	seq = vector<int>(n);
	for(int i=0; i<n; ++i)
		cin >> seq[i];
	cout << solve();	
}
