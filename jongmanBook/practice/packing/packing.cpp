#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, w, dp[100][1000], choices[100][1000];
vector<int> weights, needy;
vector<string> items;

const int INF = 1e9;

// return value is total needy weights.

// first, get total numb of subset
// second, add weights regulatoin
int packing(int idx, int totalWeight) {
	if(totalWeight > w) return 0;
	int& ret = dp[idx][totalWeight];
	if(ret != -1) return ret;
	ret = 0;
	int bestNext = -1;
	for(int next=idx+1; next<n; ++next) {
		int cand = packing(next, totalWeight + weights[next]);
		if(ret < cand) {
			ret = cand;
			bestNext = next;
		}
	}
	ret += needy[idx];
	choices[idx][totalWeight] = bestNext;
	return ret;
}

void reconstruct(int here, int weight, vector<string>& seq) {
	int next = choices[here][weight];
	if(next != -1) {
		seq.push_back(items[next]);
		reconstruct(next, weight+weights[next], seq);
	}

}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		cin >> n >> w;
		weights = needy = vector<int>(n);
		items = vector<string>(n);
		for(int i=0; i<n; ++i) {
		   	cin >> items[i] >> weights[i] >> needy[i];
		}
		memset(dp, -1, sizeof(dp));
		memset(choices, -1, sizeof(choices));
		int ans=0, maxIdx=-1;
		for(int i=0; i<n; ++i) {
			int cand = packing(i, weights[i]);
			if(ans < cand) {
				ans = cand;
				maxIdx = i;
			}
		}
		cout << ans << " ";
		if(maxIdx == -1)
			cout << 0;
		else {
			vector<string> seq;
			seq.push_back(items[maxIdx]);
			reconstruct(maxIdx, weights[maxIdx], seq);
			cout << seq.size() << "\n";
			for(string s: seq)
				cout << s << "\n";
		}
	}
	return 0;
}
