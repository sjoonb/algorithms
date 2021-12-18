#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>	
#include <algorithm>
using namespace std;

vector<int> set;
int n, dp[501], ch[501];
int k;

//  maxSet 이 반환하는 값은 그 값이 몇개의 자식을 갖고 있는지 
int maxSet(int idx) {
	if(dp[idx] != -1)
		return dp[idx];
	int ret = 0;
	for(int i=idx+1; i<=n; ++i) {
		if(set[i] > set[idx]) {
			ret = max(ret, maxSet(i) + 1);
		}
	}
	return dp[idx] = ret;
}

int maxSetCh(int idx) {
	if(dp[idx] != -1)
		return dp[idx];
	int ret = 0;
	int best = -1;
	for(int i=idx+1; i<=n; ++i) {
		if(set[i] > set[idx]) {
			int cand = maxSetCh(i) + 1;
			if(ret < cand) {
				ret = cand;
				best = i;	
			}
		}
	}
	ch[idx] = best;
	return dp[idx] = ret;
}

void biSet(int num) {
	if(k==0 || set[k-1] < num) {
		set[k++] = num;	
		return;
	}
	// 1 3 7 (5)
	int lo=0, hi=k-1;
	int mid;
	// 1 3 7 9
	//	lo
	//	hi
	//	mid
	while(lo <= hi) {
		mid = (lo+hi)/2;	
		if(set[mid] > num)
			hi = mid-1;
		else
			lo = mid+1;
	}
	set[hi+1] = num;
}

void reconstruct(int start, vector<int>& seq) {
	if(start != -1 && start != 0) seq.push_back(set[start]);
	int next = ch[start];
	if(next != -1) reconstruct(next, seq);
}

int main() {
	fstream file("input.txt");
	stringstream cin;
	cin << file.rdbuf();
	file.close();
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n;
		set = vector<int>(n+1);
		set[0] = 0;
		for(int i=1; i<=n; ++i) cin >> set[i];
//		k=0;
//		for(int i=0; i<n; ++i)
//			biSet(set[i]);
//		cout << k << "\n";
		memset(dp, -1, sizeof(dp));
		memset(ch, -1, sizeof(ch));
		cout << maxSetCh(0) << "\n";
		vector<int> seq;
		reconstruct(0, seq);
		for(int i: seq)
			cout << i;
		cout << "\n";
	}
}
