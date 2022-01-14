#include <iostream>
#include <queue>
using namespace std;

int N, K;

bool inRange(int x) {
	if(x >= 0 && x <= 1e5)
		return true;
	return false;
}

bool tryPush(queue<pair<int, int> > &q, int num, int depth, int *isVisited) {
	if(inRange(num) && !isVisited[num]) {
		q.push(make_pair(num, depth+1));
		return true;
	}
	return false;
}

// bfs
int fastest(int src) {
	int isVisited[100001] = { false, };
	queue<pair<int, int> > q;
	q.push(make_pair(src, 0));
	isVisited[src] = true;
	while(!q.empty()) {
		int num = q.front().first;
		int depth = q.front().second;
		q.pop();
		if(num == K) {
			return depth;
		}
		if(tryPush(q, num+1, depth, isVisited))
			isVisited[num+1] = 1;
		if(tryPush(q, num-1, depth, isVisited))
			isVisited[num-1] = 1;
		if(tryPush(q, num*2, depth, isVisited))
			isVisited[num*2] = 1;
	}
	return -1;
}

int count(int src, int nFastest) {
	int isVisited[100001] = { 0, };
	queue<pair<int, int> > q;
	q.push(make_pair(src, 0));
	isVisited[src] = 1;
	while(!q.empty()) {
		int num = q.front().first;
		int depth = q.front().second;
		q.pop();
		if(depth == nFastest) {
			cout << num << endl;
			continue;	
		}
		if(tryPush(q, num+1, depth, isVisited))
			isVisited[num+1] += isVisited[num];
		if(tryPush(q, num-1, depth, isVisited))
			isVisited[num-1] += isVisited[num];
		if(tryPush(q, num*2, depth, isVisited))
			isVisited[num*2] += isVisited[num];
	}
	for(int i=0; i<=20; ++i)
		cout << isVisited[i] << " ";
	return isVisited[K];
}

int main() {
	cin >> N >> K;
	int ret1 = fastest(N);
	int ret2 = count(N, ret1);
//	cout << ret1 << endl;
//	cout << ret2 << endl;
}
