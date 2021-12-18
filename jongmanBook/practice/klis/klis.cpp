#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, l, dp[500], cache[500];
vector<int> set;
vector<vector<int> > seqList;

int lis(int idx) {
	int& ret = dp[idx];
	if(ret != -1) return ret;
	ret=1;	
	for(int next=idx+1; next<n; ++next)
		if(set[next] > set[idx]) {
			int cand = 1 + lis(next);
			if(ret < cand) {
				ret = cand;
				cache[idx] = cache[next];
			} else if(ret == cand) {
				cache[idx] += cache[next];
			}
		}
	return ret;
}

void klis(int idx, vector<int>& seq) {
	//if(k<0) return;
	if(seq.size() == l) {
		if(k==0)
			for(int i=0; i<seq.size(); ++i)
				cout << seq[i] << " ";
		k--;
		//seqList.push_back(seq);
		return;
	}
	if(seq.size() + dp[idx]-1 == l && cache[idx] <= k) {
		cout << "work";
		k -= cache[idx];
		return;
	}
	for(int next = n-1; next>=idx+1; --next) {
		if(set[next] > set[idx]) {
			seq.push_back(set[next]);
			klis(next, seq);		
			seq.pop_back();
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> k;
		set = vector<int>(n);
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<n; ++i)
			cache[i] = 1;
		for(int i=0; i<n; ++i)
			cin >> set[i];
		l = 0;
		for(int i=0; i<n; ++i)
			l = max(l, lis(i));
		cout << l << "\n";
		vector<int> seq;
		seqList = vector<vector<int> >();
		k--;
//		cout << "cache: ";
//		for(int i=0; i<n; ++i)
//			cout << cache[i] << " ";
//		cout << "\n";
		for(int i=n-1; i>=0; --i) {
			seq.push_back(set[i]);	
			klis(i, seq);
			seq.pop_back();	
		}
		//sort(seqList.begin(), seqList.end());
		//reverse(seqList.begin(), seqList.end());
//		for(int i=0; i<seqList.size(); ++i) {
//			for(int j=0; j<seqList[i].size(); ++j) 
//				cout << seqList[i][j] << " ";
//			cout << "\n";
//		}
//		vector<int> ans = seqList[k-1];
//		for(int i=0; i<ans.size(); ++i)
//			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;	
}
