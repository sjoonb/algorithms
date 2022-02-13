#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> seq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for(int i=0; i<N+M; ++i) {
		int num;
		cin >> num;
		seq.push_back(num);
	}
	sort(seq.begin(), seq.end());	
	for(int i=0; i<seq.size(); ++i)
		cout << seq[i] << " ";
	return 0;
}

