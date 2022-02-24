#include <iostream>
#include <vector>
using namespace std;

string S, P;

vector<int> initLps() {
	vector<int> lps(P.size(), 0);
	int begin = 1, matched = 0;
	while(begin + matched < P.size()) {
		if(P[begin + matched] == P[matched]) {
			++matched;
			lps[begin + matched - 1] = matched;		
		} else {
			if(matched == 0)
				++begin;
			else {
				begin += matched - lps[matched-1];	
				matched = lps[matched-1];
			}
		}
	}
	return lps;
}

int kmp() {
	vector<int> lps = initLps();
	int begin = 0, matched = 0;
	while(begin + matched < S.size()) {
		if(matched < P.size() && S[begin+matched] == P[matched]) {
			++matched;
			if(matched == P.size())
				return 1;
		} else {
			if(matched == 0)
				++begin;
			else {
				begin += matched - lps[matched-1];
				matched = lps[matched-1];
			}
		}
	}
	return 0;
}

int main() {
	cin >> S >> P;
	cout << kmp();
	return 0;	
}
