#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int n, cacheCount[501], cacheLength[501], S[500];
const int MAX = 2*1e9+1;

int lis(int start) {
	int& ret = cacheLength[start+1];
	if(ret != -1) return ret;
	ret = 1;
	for(int next=start+1; next<n; ++next)
		if(start == -1 || S[start] < S[next])
			ret = max(ret, lis(next)+1);
	return ret;
}

int count(int start) {
	if(lis(start) == 1)
		return 1;
	int& ret = cacheCount[start+1];
	if(ret != -1) return ret;
	ret = 0;
	for(int next=start+1; next<n; ++next)
		if((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	return ret;	
}

void reconstruct(int start, int skip, vector<int>& ret) {
	if(start != -1)
		ret.push_back(S[start]);	
	vector<pair<int, int> > followers;
	for(int next=start+1; next<n; ++next) {
		if((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			followers.emplace_back(S[next], next);
	}
	sort(followers.begin(), followers.end());
	for(int i=0; i<followers.size(); ++i) {
		int idx = followers[i].second;	
		int cnt = count(idx);
		if(cnt <= skip) {
			skip -= cnt;
		} else {
			reconstruct(idx, skip, ret);
			break;
		}
	}
}

int main() {
	fstream file("input.txt");
	stringstream cin;
	cin << file.rdbuf();
	file.close();
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int k;
		cin >> n >> k;	
		for(int i=0; i<n; ++i)
			cin >> S[i];
		memset(cacheCount, -1, sizeof(cacheCount));
		memset(cacheLength, -1, sizeof(cacheLength));
		cout << lis(-1) -1 << endl;
		vector<int> ret;
		reconstruct(-1, k-1, ret);
		for(int i=0; i<ret.size(); ++i)
			cout << ret[i] << " ";
		cout << "\n";
	}
	return 0;
}
