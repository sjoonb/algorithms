#include <iostream>
using namespace std;

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1<<MAX_N], over[MAX_N][MAX_N];

int restore(int last, int used) {
	if(used == (1<<k)-1) return 0;
	int& ret = cache[last][used];
	if(ret != -1) return ret;
	ret = 0;
	for(int next=0; next<k; ++next)
		if((used & (1<<next)) == 0) {
			int cand = over[last][next] + restore(next, used + (1<<next));
			ret = max(ret, cand);
		}
	return ret;
}

string reconstruct(int last, int used) {
	if(used == (1 << k)-1) return "";	
	for(int next=0; next<k; ++next) {
		if(used & (1<<next)) continue;
		int ifUsed = restore(next, used + (1<<next)) + over[last][next];
		if(restore(last, used) == ifUsed) {
			return word[next].substr(over[last][next]) + reconstruct(next, used + (1<<next));
		}
	}
	return "error";
}


int overlap(string& s1, string& s2) {
	for(int len=min(s1.size(), s2.size()); len > 0; len--) {
		if(s1.substr(s1.size()-len) == s2.substr(0, len)) {
			return len;
		}
	}
	return 0;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> k;
		for(int i=0; i<k; ++i)
			cin >> word[i];
		memset(cache, -1, sizeof(cache));
		memset(over, -1, sizeof(over));
		while(true) {
			bool removed = false;
			for(int i=0; i<k && !removed; ++i)
				for(int j=0; j<k; ++j) {
					if(i != j && word[i].find(word[j]) != -1) {
						word[j] = word[k-1];
						k--;
						removed = true;
					}
				}
			if(!removed)
				break;
		}
		word[k] = "";
		for(int i=0; i<=k; ++i)
			for(int j=0; j<=k; ++j)
				over[i][j] = overlap(word[i], word[j]);
		cout << reconstruct(k, 0) << endl;
	}
	return 0;	
}
