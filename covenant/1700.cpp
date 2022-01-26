#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> electronics(101);
vector<bool> isPlugged(101, false);

void unplug(int idx) {
	int nCand = n;
	vector<bool> candPlugged(101, false);
	for(int i=1; i<101; ++i)
		candPlugged[i] = isPlugged[i];
	while(nCand > 1 && idx < k) {
		int cand = electronics[idx];
		if(candPlugged[cand]) {
			candPlugged[cand] = false;
			nCand--;
		}
		idx++;		
	}
	for(int i=1; i<101; ++i)
		if(candPlugged[i]) {
			isPlugged[i] = false;
			return;
		}
	return;
}

int solve() {
	if(n >= k) 
		return 0;
	int idx=0;
	int plugged = 0;
	while(plugged < n && idx < k) {
		int e = electronics[idx];
		if(!isPlugged[e]) {
			isPlugged[e] = true;
			plugged++;
		}
		idx++;
	}
	int plugoff = 0;
	for(; idx<k; ++idx) {
		int e = electronics[idx];	
		if(!isPlugged[e]) {
			unplug(idx+1);
			isPlugged[e] = true;
			plugoff++;
		}
	}
	return plugoff;	
}

int main() {
	cin >> n >> k;

	for(int i=0; i<k; ++i)
		cin >> electronics[i];	

	cout << solve();
}
