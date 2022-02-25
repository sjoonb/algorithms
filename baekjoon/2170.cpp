#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define left first
#define right second

int N;
vector<pair<int, int> > seq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for(int i=0; i<N; ++i) {
		int l, r;	
		cin >> l >> r;
		seq.push_back({ l, r });
	}
	sort(seq.begin(), seq.end());
	int l = seq[0].left;
	int r = seq[0].right;
	int ret = 0;
	for(int i=1; i<seq.size(); ++i) {
		if(seq[i].left > r) {
			ret += (r-l);
			l = seq[i].left;
			r = seq[i].second;
		} else if(seq[i].right > r) {
			r = seq[i].right;	
		}
	}
	ret += r-l;
	cout << ret;
	return 0;	
}
