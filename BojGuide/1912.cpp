#include <iostream>
#include <algorithm>
using namespace std;

int N;
int seq[100000];

int solve() {
	int ret = -1001;
	int tempSum = 0;
	int j = 0;
	for(int i=0; i<N; ++i) {
		tempSum += seq[i];	
		ret = max(ret, tempSum);
		if(tempSum < 0) {
			tempSum = 0;	
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> seq[i];
	cout << solve();
	return 0;
}
