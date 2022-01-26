#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool isVisited[100001];

bool inRange(int x) {
	if(x >= 0 && x <= 1e5)
		return true;
	return false;
}

int bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	while(!q.empty()) {
		int num = q.front().first;
		int depth = q.front().second;
		q.pop();
		for(int nextNum = num; nextNum <= 1e5; nextNum *= 2) {
			if(nextNum == K)
				return depth;
			isVisited[nextNum] = true;
			if(inRange(nextNum - 1) && !isVisited[nextNum - 1]) {
				q.push(make_pair(nextNum - 1, depth+1));
				isVisited[nextNum - 1] = true;
			}
			if(inRange(nextNum + 1) && !isVisited[nextNum + 1]) {
				q.push(make_pair(nextNum + 1, depth+1));
				isVisited[nextNum + 1] = true;
			}
			if(nextNum == 0)
				break;
		}
	}
	return 0;
}

int main() {
	cin >> N >> K;
	cout << bfs();
}
