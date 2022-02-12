#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int X[200000];

int numOfObj(int dist) {
	int ret = 1;
	int i = 1;
	int j = 0;
	while(i < N) {
		if(X[i] - X[j] >= dist) {
			j = i;
			ret++;
		}
		i++;
	}
	return ret;
}

int bisection(int lo, int hi) {
	for(int i=0; i<200; ++i) {
		int mid = (lo + hi) / 2;
		int nObj = numOfObj(mid);
		if(nObj < C)
			hi = mid;
		else
			lo = mid;
	}
	return (lo + hi) / 2;	
}

int main() {
	cin >> N >> C;
	for(int i=0; i<N; ++i)
		cin >> X[i];
	sort(X, X+N);
	cout << bisection(0, 2e5+1);
	return 0;	
}
