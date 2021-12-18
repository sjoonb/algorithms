#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int bfs(const vector<int>& perm) {
	int n = perm.size();	
	vector<int> sorted = perm;
	sort(sorted.begin(), sorted.end());
	queue<vector<int> > q;
	map<vector<int>, int> distance;
	distance[perm] = 0;
	q.push(perm);
	while(!q.empty()) {
		vector<int> here = q.front();	
		q.pop();
		if(here == sorted)
			return distance[here];
		int cost = distance[here];
		for(int i=0; i<n; ++i) {
			for(int j=i+2; j<=n; ++j) {
				reverse(here.begin()+i, here.begin()+j);
				if(distance.count(here) == 0) {
					distance[here] = cost+1;	
					q.push(here);
				}
				reverse(here.begin()+i, here.begin()+j);
			}
		}
	}
	return -1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr = vector<int>(n);
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	cout << bfs(arr) << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;	
}
