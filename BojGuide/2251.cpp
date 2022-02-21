#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

#define A 0
#define B 1
#define C 2

int sizes[3];
unordered_set<int> visited;
set<int> ret;

int get(int state, int index) {
	return (state >> (index << 3) & 255);
}

int _set(int state, int index, int value) {
	return state &~ (255 << (index << 3)) | (value << (index << 3));
}

void print(int state) {
	for(int i=0; i<3; ++i)
		cout << get(state, i) << " ";	
	cout << "\n";
}

void dfs(int state) {
	if(visited.find(state) != visited.end())
		return;
	visited.insert(state);
	if(get(state, A) == 0) {
		ret.insert(get(state, C));
	}
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j) {
			if(i == j) 
				continue;	
			int nextState;
			int iVal = get(state, i);
			int jVal = get(state, j);
			int jCap = sizes[j] - jVal;
			if(iVal - jCap > 0) {
				//swell value amount of jCap only and remain iVal-jCap
				nextState = _set(state, j, jVal + jCap);
				nextState = _set(nextState, i, iVal - jCap);
			} else {
				//swell all (iVal)
				nextState = _set(state, j, jVal + iVal);
				nextState = _set(nextState, i, 0);
			}
			dfs(nextState);
		}
}

int main() {
	for(int i=0; i<3; ++i)
		cin >> sizes[i];
	int state = 0; // 8bit * 3 (A, B, C)
	state = _set(state, C, sizes[C]);
	dfs(state);
	for(auto it=ret.begin(); it!=ret.end(); ++it)
		cout << *it << " ";
	return 0;	
}
