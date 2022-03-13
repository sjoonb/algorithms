#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int seq[1001];
int dpL[1001];
int dpR[1001];

int longestLeft(int idx) {
	int &ret = dpL[idx];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int next = idx-1; next>=0; --next) {
		if(seq[next] < seq[idx])
			ret = max(ret, longestLeft(next) + 1);
	}
	return ret;
}

int longestRight(int idx) {
	int &ret = dpR[idx];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int next = idx+1; next<N; ++next) {
		if(seq[next] < seq[idx])
			ret = max(ret, longestRight(next) + 1);
	}
	return ret;
}

int bitonic(int idx) {
	int a = longestLeft(idx);
	int b = longestRight(idx);
	return a + b + 1;
}

int main() {
	memset(dpL, -1, sizeof(dpL));
	memset(dpR, -1, sizeof(dpR));
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> seq[i];
	}
	int ret = 1;
	for(int i=0; i<N; ++i) {
		ret = max(ret, bitonic(i));
	}
	cout << ret;
	return 0;
}
