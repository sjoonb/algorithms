#include <iostream>
#include <vector>
using namespace std;

bool areFriends[10][10];
int n, m;

int countPairings(bool taken[10]) {
	int here = -1;
	for(int i=0; i<n; ++i)
		if(!taken[i]) {
			here = i;
			break;
		}
	if(here == -1) return 1;
	int ret=0;
	for(int there=here+1; there<n; ++there) {
		if(!taken[here] && !taken[there] && areFriends[here][there]) {
			taken[here] = taken[there] = true;
			ret += countPairings(taken);
			taken[here] = taken[there] = false;
		}
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> m;	
		memset(areFriends, 0, sizeof(areFriends));
		for(int i=0 ; i<m; ++i) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		bool taken[10];
		memset(taken, 0, sizeof(taken));
		cout << countPairings(taken) << "\n";
	}
	return 0;	
}
