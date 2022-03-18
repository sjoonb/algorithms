#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > meetings;

int solve() {
	int l, r, ret;
	l = meetings[0].first;
	r = meetings[0].second;
	ret = 1;
	for(int i=1; i<N; ++i) {
		int candL = meetings[i].first;
		int candR = meetings[i].second;
		if(candL >= r) {
			ret++;
			l = candL;
			r = candR;
		} else if(candR < r) {
			r = candR;
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		int start, end;
		cin >> start >> end;
		meetings.push_back({start, end});
	}
	sort(meetings.begin(), meetings.end());
	cout << solve();
	return 0;
}
