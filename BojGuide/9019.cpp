#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool isVisited[10000];
string method = "DSLR";

void command(queue<pair<int, string> > &q, int num, string cmd, char ch) {
	switch(ch) {
		case 'D':
			num = num*2 % (int)1e4;
			break;	
		case 'S':
			num -= 1;
			if(num < 0)
				num = 9999;
			break;
		case 'L':
			num = (num % 1000) * 10 + (num / 1000);
			break;
		case 'R': 
			num = (num % 10) * 1000 + num / 10;
			break;
	}
	if(isVisited[num])
		return;
	isVisited[num] = true;	
	cmd += ch;
	q.push({num, cmd});
}

string bfs(int src, int dest) {
	queue<pair<int, string> > q;
	q.push({src, ""});
	while(!q.empty()) {
		int num = q.front().first;
		string cmd = q.front().second;;
		q.pop();
		if(num == dest)
			return cmd;
		for(int i=0; i<4; ++i)
			command(q, num, cmd, method[i]); 
	}
	return "";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		memset(isVisited, false, sizeof(isVisited));
		int src, dest;
		cin >> src >> dest;
		cout << bfs(src, dest) << "\n";
	}
	return 0;
}
