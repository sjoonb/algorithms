#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_V = 100;

const int V = 6;

int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int fordFulkerson(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	while(true) {
		vector<int> parent(V, -1);
		queue<int> q;
		q.push(source);
		parent[source] = source;
		while(!q.empty() && parent[sink] == -1) {
			int here = q.front(); q.pop();	
			for(int there=0; there<V; ++there) {
				if(cap[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					parent[there] = here;
					q.push(there);	
				}
			}
		}
		if(parent[sink] == -1) break;
		int amount = INF;
		for(int p=sink; p!=source; p=parent[p]) {
			amount = min(amount, cap[parent[p]][p] - flow[parent[p]][p]);
		}
		for(int p=sink; p!=source; p=parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;	
		}
		totalFlow += amount;
	}
	return totalFlow;	
}

int main() {
	cap[0][1] = 10;
	cap[0][2] = 5;
	cap[1][3] = INF;
	cap[1][4] = INF;
	cap[2][4] = INF;
	cap[3][5] = 9;
	cap[4][5] = 7;
	cout << fordFulkerson(0, 5) << "\n";
}
