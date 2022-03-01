#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, K;

int main() {
	cin >> N >> M >> K;	
	int maxTeam = min(N/2, M);
	int remain = (N + M) - maxTeam * 3;
	K -= remain;
	if(K > 0) {
		maxTeam = max(0, maxTeam - (int)ceil(K/3.0));
	}
	cout << maxTeam;
	return 0;
}
