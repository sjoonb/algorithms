#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > seq;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if(a.first == b.first)
		return a.second < b.second;	
	return a.first < b.first;
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		int x, y;
		cin >> x >> y;
		seq.push_back({x, y});
	}
	sort(seq.begin(), seq.end(), cmp);
	for(int i=0; i<N; ++i)
		cout << seq[i].first << " " << seq[i].second << "\n";
	return 0;	
}
