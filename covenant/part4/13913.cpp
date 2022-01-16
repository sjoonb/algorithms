#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;

bool isVistied[100001];
int parent[100001];

queue<pair<int, int> > q;	

bool inRange(int x) {
	if(x >= 0 && x <= 1e5)
		return true;
	return false;	
}

bool tryPush(int num, int depth) {
	if(inRange(num) && !isVistied[num]) {
		q.push(make_pair(num, depth));
		return true;
	}
	return false;
}

int bfs() {
	q.push(make_pair(N, 0));
	isVistied[N] = true;
	while(!q.empty()) {
		int num = q.front().first;	
		int depth = q.front().second;	
		q.pop();
		if(num == K)
			return depth;
		if(tryPush(num+1, depth+1)) {
			isVistied[num+1] = true;
			parent[num+1] = num;
		}
		if(tryPush(num-1, depth+1)) {
			isVistied[num-1] = true;
			parent[num-1] = num;
		}
		if(tryPush(num*2, depth+1)) {
			isVistied[num*2] = true;
			parent[num*2] = num;
		}
	}
	return 0;
}


void upToRoot(int num, vector<int> &vec) {
	vec.push_back(num);	

	if(num == N)
		return;
	else
		return upToRoot(parent[num], vec);
}

int main() {
	cin >> N >> K;
	cout << bfs() << endl;	
	vector<int> ret = vector<int>();
	upToRoot(K, ret);
	reverse(ret.begin(), ret.end());
	for(int i=0; i<ret.size(); ++i)
		cout << ret[i] << " ";
}

