#include <iostream>
#include <deque>
using namespace std;

struct RNG {
	unsigned seed;
	RNG(): seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int solve(int k, int n) {
	int sum = 0, ret = 0;
	deque<int> dq;
	RNG rng = RNG();
	for(int i=0; i<n; ++i) {
		int signal = rng.next();
		dq.push_back(signal);
		sum += signal;
		while(!dq.empty() && sum > k) {
			sum -= dq.front();
			dq.pop_front();	
		}
		if(sum == k)
			ret++;
	}
	return ret;	
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		int k, n;
		cin >> k >> n;
		cout << solve(k, n) << "\n";
	}
}
