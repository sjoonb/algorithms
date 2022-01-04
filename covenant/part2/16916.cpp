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
			j = P[j-1];		
		}
		if(P[i] == P[j])
			lps[i] = ++j;
	}
	for(int i=0; i<lps.size(); ++i)
		cout << lps[i] << " ";
}

int main() {
	cin >> S >> P;	
	initLps();	
}
