#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 20;
const int WHITE = 1;
const int BLACK = 0;

int maskSum[1024], maskLen[1024];
int candidates[10][46][1024];

int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
int q, sum[MAXN*MAXN], length[MAXN*MAXN], known[MAXN*MAXN]; 

void calcMasks() {
	memset(maskSum, 0, sizeof(maskSum));
	memset(maskLen, 0, sizeof(maskLen));
	for(int mask=0; mask<1024; mask++)
		for(int i=0; i<10; ++i)
			if(mask & (1<<i)) {
				maskSum[mask]+=i;	
				maskLen[mask]++;
			}
}

int getSize(int mask) { return maskLen[mask]; }

int getSum(int mask) { return maskSum[mask]; }

void generateCandidates() {
	memset(candidates, 0, sizeof(candidates));	
	for(int set=0; set<1024; set+=2) {
		int l = getSize(set), s = getSum(set);	
		int subset = set;
		while(true) {
			candidates[l][s][subset] |= (set & ~subset);
			if(subset==0) break;
			subset = (subset - 1) & set;
		}
	}
}

void put(int y, int x, int val) {
	for(int h=0; h<2; ++h)
		known[hint[y][x][h]] += (1<<val);
	value[y][x] = val;
}

void remove(int y, int x, int val) {
	for(int h=0; h<2; ++h)
		known[hint[y][x][h]] -= (1<<val);
	value[y][x] = 0;
}

int getCandHint(int hint) {
	return candidates[length[hint]][sum[hint]][known[hint]];
}

int getCandCoord(int y, int x) {
	return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

void printSolution() {
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j)
			cout << value[i][j] << " ";
		cout << "\n";
	}
}

bool search() {
	int y=-1, x=-1, minCands = 1023;	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(color[i][j] == WHITE && value[i][j] == 0) {
				int cands = getCandCoord(i, j);
				if(getSize(minCands) > getSize(cands)) {
					minCands = cands;
					y=i; x=j;
				}
			}
	if(minCands == 0) return false;
	if(y==-1) {
		printSolution();
		return true;	
	}
	for(int val=1; val<=9; ++val) {
		if(minCands & (1<<val)) {
			put(y, x, val);
			search();
			remove(y, x, val);
		}
	}
	return true;
}

void input() {
	 cin >> n;	
	 for(int i=0; i<n; ++i)
		 for(int j=0; j<n; ++j)
			 cin >> color[i][j];
	 memset(hint, -1, sizeof(hint));
	 cin >> q;
	 int dy[2] = { 0, 1 };
	 int dx[2] = { 1, 0 };
	 for(int i=0; i<q; ++i) {
		int y, x, direction;
		cin >> y >> x >> direction >> sum[i];
		--y, --x;
		length[i] = 0;
		while(true) {
			y += dy[direction]; x += dx[direction];
			if(y >= n || x >= n || color[y][x] == BLACK) break;
			hint[y][x][direction] = i;
			length[i]++;
		}
	 }
	 memset(known, 0, sizeof(known));
}

int main() {
	calcMasks();
	generateCandidates();

	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		input();
		memset(value, 0, sizeof(value));
		search();
	}
	return 0;
}

