#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> clocks;
const int INF = 1e9;

void switchOn(int num) {
	vector<int> v;
	switch(num) {
		case 0: v = {0, 1, 2}; break;	
		case 1: v = {3, 7, 9, 11}; break;	
		case 2: v = {4, 10, 14, 15}; break;	
		case 3: v = {0, 4, 5, 6, 7}; break;	
		case 4: v = {6, 7, 8, 10, 12}; break;	
		case 5: v = {0, 2, 14, 15}; break;	
		case 6: v = {3, 14, 15}; break;	
		case 7: v = {4, 5, 7, 14, 15}; break;	
		case 8: v = {1, 2, 3, 4, 5}; break;	
		case 9: v = {3, 4, 5, 9, 13}; break;	
	}
	for(int i=0; i<v.size(); ++i) {
		int snum = clocks[v[i]];		
		snum += 3;
		if(snum>12) snum = 3;
		clocks[v[i]] = snum;
	}
}

bool areAligned() {
	for(int i=0; i<16; ++i)
		if(clocks[i] != 12) {
			return false;
		}
	return true;
}

int clock(int switchNum) {
	if(switchNum == 10) return areAligned() ? 0 : INF;
	int ret=INF;
	for(int i=0; i<4; ++i) { 
		ret = min(ret, clock(switchNum+1) + i);
		switchOn(switchNum);
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		clocks = vector<int>(16);
		for(int i=0; i<16; ++i)
			cin >> clocks[i];
		int ret = clock(0);
		if(ret == INF)
			cout << "-1";
		else
			cout << ret;
		cout << "\n";
	}
	return 0;	
}
