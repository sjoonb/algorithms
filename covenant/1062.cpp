#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> words;
const string alpha = "bdefghjklmopqrsuvwxyz";
const string except = "acint";

int countMatching(const int word) {
	int ret = 0;
	for(int i=0; i<words.size(); ++i)
		if(!(words[i] & ~word))
			ret++;
	return ret;
}

int dfs(int src, int depth, int word) {
	if(depth == 0) {
		return countMatching(word);	
	}
	int ret = 0;
	for(int i=src; i<alpha.size(); ++i) {
		int j = alpha[i] - 'a';
		ret = max(ret, dfs(i+1, depth-1, word ^ (1 << j)));
	}
	return ret;	
}

int solve() {
	if(K < 5)
		return 0;
	int word = 0;
	for(int i=0; i<except.size(); ++i) {
		int j = except[i] - 'a';	
		word |= (1 << j);
	}
	int ret = dfs(0, K-5, word);
	return ret;	
}

void input() {
	words = vector<int>(N);
	for(int i=0; i<N; ++i) {
		string word;
		cin >> word;
		int bitWord=0;
		for(int j=0; j<word.size(); ++j) {
			int k = word[j] - 'a';
			bitWord |= (1 << k);
		}
		words[i] = bitWord;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	input();
	cout << solve();
	return 0;	
}
