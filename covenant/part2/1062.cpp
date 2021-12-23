#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// using bitmask?

vector<int> words;
int nextCand[21];

int numMatchWord(int bit) {
	int ret = 0;
	for(int i=0; i<words.size(); ++i)
		if(!(words[i] & ~bit))
			ret++;
	return ret;
}

int dfs(int src, int depth, int bit=0) {
	if(depth == 0) {
		return numMatchWord(bit);
	}
	int ret = 0;
	for(int next=src+1; next<21; ++next) {
		int cand = nextCand[next];	
		bit ^= (1 << cand);
		ret = max(dfs(next, depth-1, bit), ret);
		bit ^= (1 << cand);
	}
	return ret;
}

int binarize(const string &word, const string &exception) {
	int bit = 0;
	for(int i=0; i<word.size(); ++i) {
		if(exception.find(word[i]) != string::npos)
			continue;
		bit |= (1 << (word[i] - 'a')); 
	}
	return bit;	
}

int solve(int n, int k) {
	if(k < 5) {
		string tmp;
		for(int i=0; i<n; ++i)
			cin >> tmp;
		return 0;	
	}

	words = vector<int>(n);
	string exception = "antic";
	for(int i=0; i<n; ++i) {
		string word;
		cin >> word;
		words[i] = binarize(word, exception);
	}
	int j=0;
	for(int i=0; i<26; ++i) {
		if(exception.find(i + 'a') != string::npos)
			continue;
		nextCand[j++] = i;
	}
	int ret = dfs(-1, k-5);
	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
}
