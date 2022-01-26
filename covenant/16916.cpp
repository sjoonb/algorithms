#include <iostream>
#include <vector>
using namespace std;

string S, P;
vector<int> lps;


void initLps() {
	lps = vector<int>(P.size(), 0);	
	int j = 0;
	for(int i=1; i<P.size(); ++i) {
		while(j > 0 && P[i] != P[j]) {
			j = lps[j-1];		
		}
		if(P[i] == P[j])
			lps[i] = ++j;
	}
}

int kmp() {
	int j = 0;
	for(int i=0; i<S.size(); ++i) {
		if(j >= P.size())
			break;

		while(j > 0 && S[i] != P[j]) {
			j = lps[j-1];	
		}
		if(S[i] == P[j])
			j++;
	}
	return (j == P.size()) ? 1 : 0;
}

int main() {
	cin >> S;
	cin >> P;	
	initLps();	
	cout << kmp();
}
