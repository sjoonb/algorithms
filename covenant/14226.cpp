#include <iostream>
#include <queue>
using namespace std;

int S;
bool isVisited[1001][1001];

bool inRange(int x) {
	if(x >= 0 && x <= 1000)
		return true;
	return false;
}

int bfs(int src) {
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(src, 0, 0)); // num, seconds, clipboard
	isVisited[src][0] = true;
	while(!q.empty()) {
		int num = get<0>(q.front());
		int sec = get<1>(q.front());
		int clip = get<2>(q.front());
		q.pop();
		if(num == S)
			return sec;
		if(!isVisited[num][num]) {
			q.push(make_tuple(num, sec+1, num));	
			isVisited[num][num] = true;
		}
		if(clip && inRange(num + clip) && !isVisited[num + clip][clip]) {
			q.push(make_tuple(num + clip, sec+1, clip));
			isVisited[num + clip][clip] = true;
		}
		if(inRange(num-1) && !isVisited[num-1][clip]) {
			q.push(make_tuple(num-1, sec+1, clip));
			isVisited[num-1][clip] = true;	
		}
	}
	return 0;	
}

int main() {
	cin >> S;
	cout << bfs(1);
}
