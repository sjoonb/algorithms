#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int lunchBox(const vector<int>& micro, const vector<int>& eat) {
	vector<pair<int, int> > pairs;
	for(int i=0; i<n; ++i) {
		pairs.emplace_back(eat[i], micro[i]);	
	}
	sort(pairs.begin(), pairs.end());
	int ret=0, waveSum=0;
	for(int i=n-1; i>=0; --i) {
		pair<int, int> pair = pairs[i];	
		waveSum += pair.second;
		ret = max(ret, waveSum + pair.first);
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		vector<int> micro, eat;
		cin >> n;	
		micro = eat = vector<int>(n);
		for(int i=0; i<n; ++i) {
			cin >> micro[i];
		}
		for(int i=0; i<n; ++i) {
			cin >> eat[i];
		}
		cout << lunchBox(micro, eat) << "\n";
	}
	return 0;
}
