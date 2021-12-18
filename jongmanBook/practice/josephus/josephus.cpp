#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> josephus(int n, int k) {
	queue<int> survivors;
	for(int i=0; i<n; ++i)
		survivors.push(i+1);
	int cnt=0;
	while(survivors.size() > 2) {
		int soldier = survivors.front();
		survivors.pop();
		if(cnt % k != 0)
			survivors.push(soldier);
		cnt++;
	}
	vector<int> ret;

	int a = survivors.front();
	ret.push_back(a);
	survivors.pop();

	int b = survivors.front();
	ret.push_back(b);
	survivors.pop();
	
	sort(ret.begin(), ret.end());
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int n, k;
		cin >> n >> k;
		vector<int> ans = josephus(n, k);
		for(int i=0; i<ans.size(); ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
}
