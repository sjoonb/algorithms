#include <iostream>
using namespace std;

const int MAX = 1e9+1;
int n, p, l, length[51];

void precalc() {
	length[0] = 1;
	for(int i=1; i<=50; ++i)
		length[i] = min(MAX, 2*length[i-1] + 2);
}

void curve(const string& seed, int gen) {
	if(gen == 0) {
		cout << seed;
		return;
	}
	for(int i=0; i<seed.size(); ++i) {
		if(seed[i] == 'X')
			curve("X+YF", gen-1);
		else if(seed[i] == 'Y')
			curve("FX-Y", gen-1);
		else
			cout << seed[i];
	}
}

char expand(const string& dragonCurve, int gen, int skip) {
	if(gen == 0)
		return dragonCurve[skip];
	for(int i=0; i<dragonCurve.size(); ++i)
		if(dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if(skip >= length[gen])
				skip -= length[gen];
			else if(dragonCurve[i] == 'X')
				return expand("X+YF", gen-1, skip);
			else
				return expand("FX-Y", gen-1, skip);
		} else if(skip > 0) {
			--skip;
		} else {
			return dragonCurve[i];
		}
	return '0';
}

int main() {
	int cases;
	cin >> cases;
	precalc();
	for(int c=0; c<cases; ++c) {
		cin >> n >> p >> l;
		for(int i=0; i<l; ++i) {
			cout << expand("FX", n, p+i-1);
		}
		cout << "\n";
	}
	return 0;	
}
