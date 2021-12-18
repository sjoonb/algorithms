#include <iostream>
#include <cmath>
using namespace std;

int winRate(int gamePlay, int numWin, int moreWin) {
	int ret = ((double)(numWin + moreWin) / (gamePlay + moreWin))*100;
	return ret;	
}

int winStraight(int gamePlay, int numWin) {
	double rate = (double)numWin / gamePlay;
	int z = rate * 100;
	double temp = (((long long)numWin + 2e9) / ((long long)gamePlay + 2e9))*100;
	if(temp <= z) return -1;
	int lo=0, hi=2e9 + 1;	
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(winRate(gamePlay, numWin, mid) >= z+1)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n, m;
		cin >> n >> m;
		cout << winStraight(n, m) << "\n";
	}
}
