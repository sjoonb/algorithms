#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// using bitmask?

vector<int> alpha;

int dfs(int src, int depth) {
	if(depth == 0) {
		
	}
	return 0;
}

int solve(int n, int k) {
	if(k<5)
		return 0;

	for(int i='a'; i<'z'; ++i) {
		if(i != 'a' || i != 'n' || i != 't' || i != 'i' || i != 'c')
			alpha.push_back(i-'a');
	}
	
	cout << "\n";
	for(int i=0; i<21; ++i)
		cout << (char)(alpha[i] + 'a');

	vector<int> words(n);

	for(int i=0; i<n; ++i) {
		string str;
		cin >> str;
		int word = 0;
		for(int j=0; j<str.size(); ++j) {
			word |= (1 << (str[j] - 'a'));
		}
		words[i] = word;
	}
	for(int i=0; i<words.size(); ++i)
		cout << words[i] << endl;

	int r = k-5;

	int ret = dfs(-1, r);

	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
}
