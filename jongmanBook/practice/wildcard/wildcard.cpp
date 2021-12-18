#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

string wildcard, card;
string W, S;

int dp[101][101];

bool match(const string& w, const string& s) {
	int& ret = dp[w.size()][s.size()];
	if(ret != -1) return ret;
	int pos=0;
	while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) ++pos;
	if(pos == w.size())
		return pos == s.size();
	if(w[pos] == '*') {
		for(int skip=0; pos+skip <= s.size(); ++skip) 
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;
	}
	return ret = false;	
}

int match2(int w, int s) {
	int& ret = dp[w][s];
	if(ret != -1)
		return ret;
	if(w < W.size() && s < S.size()	&& (W[w] == '?' || W[w] == S[s]))
		return match2(w+1, s+1);
	if(w == W.size())
		return s == S.size();
	if(W[w] == '*') {
		if(match2(w+1, s) || (s < S.size() && match2(w, s+1)))
			return true;
	}
	return ret = false;
}

int main() {
	ifstream file("input.txt");
	stringstream cin;
	cin << file.rdbuf();
	file.close();
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> W;
		int n;
		cin >> n;
		vector<string> ret;
		for(int i=0; i<n; ++i) {
			cin >> S;	
			memset(dp, -1, sizeof(dp));
			if(match2(0, 0))
				ret.push_back(S);
		}
		sort(ret.begin(), ret.end());
		for(int i=0; i<ret.size(); ++i)
			cout << ret[i] << "\n";
	}
	return 0;	
}
