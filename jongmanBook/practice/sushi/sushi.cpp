#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int n, m, preference[20], price[20], dp[201];

int sushi() {
	int ret = 0;
	dp[0] = 0;
	for(int budget=1; budget<=m; ++budget) {
		int cand = 0;
		for(int dish=0; dish<n; ++dish)
			if(budget >= price[dish])
				cand = max(cand, dp[(budget - price[dish]) % 201] + preference[dish]);
		dp[budget % 201] = cand;
		ret = cand;
	}
	return ret;	
}

int main() {
	fstream file("input.txt");
	stringstream cin;
	cin << file.rdbuf();
	file.close();
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> m;
		m /= 100;
		for(int i=0; i<n; ++i) {
			cin >> price[i] >> preference[i];
			price[i] /= 100;
		}
		cout << sushi() << "\n";
	}
	return 0;
}
