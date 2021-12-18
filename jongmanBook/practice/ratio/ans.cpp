#include <iostream>
#include <cmath>
using namespace std;

long long L = 2e9;

int ratio2(long long b, long long a) {
	return (a * 100) / b;	
}

int needGames(long long games, long long won) {
	if(ratio2(games, won) == ratio2(games + L, won + L))
		return -1;	
	long long lo=0, hi=L;
	while(lo+1 < hi) {
		long long mid = (lo + hi)/2;
		if(ratio2(games, won) == ratio2(games+mid, won+mid))
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int mathSolution(long long games, long long won) {
	long long r = ((won * 100) / games) + 1;
	int x = (r*games - 100*won) / ((long long)100 - r);
	return x;
}

int main() {
	cout.precision(13);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n, m;
		cin >> n >> m;
		//cout << needGames(n, m) << "\n";
		cout << mathSolution(n, m) << "\n";
	}
}

