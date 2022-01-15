#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool isVisited[100001];
queue<pair<int, int>> q;	

bool inRange(int x) {
	if(x >= 0 && x <= 1e5)
		return true;
	return false;
}

void tryPush(int num, int depth) {
	if(inRange(num) && !isVisited[num])
		q.push(make_pair(num, depth));	
}

void solve() {
	int fastest = 0;
	q.push(make_pair(N, 0));
	int ret = 0;
	while(!q.empty()) {
		int num = q.front().first;	
		int depth = q.front().second;	
		q.pop();

		isVisited[num] = true;

		if(fastest && depth >= fastest) {
			if(depth == fastest && num == K)
				ret++;	
			continue;
		}

		if(!fastest && num == K) {
			fastest = depth;
			ret = 1;
			continue;
		}

		tryPush(num+1, depth+1);
		tryPush(num-1, depth+1);
		tryPush(num*2, depth+1);
	}
	cout << fastest << endl;
	cout <<	ret;
}

int main() {
	cin >> N >> K;
	solve();
	return 0;
}
