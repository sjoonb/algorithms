#include <iostream>
#include <vector>
using namespace std;

int n, k, m, length[50];
double T[50][50];

vector<double> getProb1() {
	double c[5][50];
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;
	for(int time=1; time<=k; ++time) 
		for(int song=0; song<n; ++song) {
			double& prob = c[time % 5][song];
			prob = 0;
			for(int last=0; last<n; ++last)
				prob += c[(time-length[last] + 5) % 5][last] * T[last][song];
		}
	vector<double> ret(n);
	for(int song=0; song<n; ++song) {
		for(int start = k-length[song]+1; start<=k; ++start)
			ret[song] += c[start % 5][song];
	}
	return ret;
}


int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> k >> m;
		for(int i=0; i<n; ++i)
			cin >> length[i];
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cin >> T[i][j];
		vector<double> ret = getProb1();
		for(int i=0; i<m; ++i) {
			int song;
			cin >> song;
			cout << ret[song] << " ";	
		}
		cout << "\n";
	}
	return 0;	
}
