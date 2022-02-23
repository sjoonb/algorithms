#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;

bool isVisited[1000001];
int dist[1000001];

bool inRange(int x) {
	if(x >= 1 && x <= F)
		return true;
	return false;
}

void push(int here, int there, queue<int> &q) {
	if(inRange(there) && !isVisited[there]) {
		q.push(there);
		isVisited[there] = true;
		dist[there] = dist[here] + 1;
	}
}

int bfs(int start) {
	queue<int> q;
	q.push(start);
	isVisited[start] = true;
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		if(here == G)
			return dist[here];
		push(here, here+U, q);
		push(here, here-D, q);
	}
	return -1;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	int ret = bfs(S);
	if(ret != -1)
		cout << ret;
	else
		cout << "use the stairs";
	return 0;
}
