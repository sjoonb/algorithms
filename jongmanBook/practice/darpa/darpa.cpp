#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
double maxDist, dp[201][100];
double places[200];


void input() {
	cin >> n >> m;	
	for(int i=0; i<m; ++i)
		cin >> places[i];
}

void search(int start, vector<int> placed) {
	if(placed.size() == n) {
		double minDist = 1000;
		for(int i=1; i<placed.size(); ++i) {
			minDist = min(minDist, places[placed[i]] - places[placed[i-1]]);	
		}
		maxDist = max(maxDist, minDist);
		return;
	}
	for(int next=start+1; next<m; ++next) {
		placed.push_back(next);
		search(next, placed);
		placed.pop_back();
	}
}

void search2(int start, int nCamera, double minDist) {
	if(minDist <= maxDist) return;
	if(nCamera == n) {
		maxDist = max(maxDist, minDist);
		return;
	}
	for(int next=start+1; next<m; ++next) {
		double nextMinDist = (start == -1) ? minDist : min(minDist, places[next] - places[start]);
		search2(next, nCamera+1, nextMinDist);
	}
}

double search3(int start, int nCamera, double minDist) {
	if(nCamera == n) {
		return minDist;
	}
//	double& ret = dp[start+1][nCamera];
//	if(ret != -1.0) return ret;
	double ret = 0;
	for(int next=start+1; next<m; ++next) {
		double nextMinDist = (start == -1) ? minDist : min(minDist, places[next] - places[start]);
		ret = max(ret, search3(next, nCamera+1, nextMinDist));
	}
	return ret;	
}

int main() {
	cout.precision(2);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		input();
//		vector<int> placed;
//		maxDist = 0;
//		search2(-1, 0, 1000);
		for(int i=0; i<201; ++i)
			for(int j=0; j<100; ++j)
				dp[i][j] = -1.0;
		cout << fixed;
		cout << search3(-1, 0, 241) << "\n";
		//cout << maxDist << "\n";
	}
}
