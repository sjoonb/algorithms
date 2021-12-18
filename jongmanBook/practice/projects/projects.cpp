#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int V;
int n, m;
int capacity[100][100], flow[100][100];
int profit[100], cost[100];
int require[100][100];

int networkFlow(int source, int sink) {
	int totalFlow=0;
	while(true) {
		vector<int> parent(V, -1);
		queue<int> q;
		q.push(source);
		parent[source] = source;
		while(!q.empty() && parent[sink] == -1) {
			int here = q.front(); q.pop();
			for(int there=0; there<V; ++there)
				if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}
		if(parent[sink] == -1) break;
		int amt=INF;
		for(int p=sink; p!=source; p=parent[p]) {
			amt = min(amt, capacity[parent[p]][p] - flow[parent[p]][p]);	
		}
		for(int p=sink; p!=source; p=parent[p]) {
			flow[parent[p]][p] += amt;
			flow[p][parent[p]] -= amt;
		}
		totalFlow += amt;
	}
	return totalFlow;
}

int maxProfit() {
	const int SRC=0, SNK=1;
	V = n + m + 2;
	memset(capacity, 0, sizeof(capacity));
	memset(flow, 0, sizeof(flow));
	for(int i=0; i<n; ++i)
		capacity[SRC][i+2] = profit[i];
	for(int i=0; i<m; ++i)
		capacity[2+n+i][SNK] = cost[i];
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(require[i][j])
				capacity[2+i][2+n+j] = INF;
	int M = accumulate(profit, profit+n, 0);
	int C = networkFlow(SRC, SNK);
	cout << "M: " << M << " C: " << C << "\n";
	return M-C;
}

int main()  {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		memset(require, 0, sizeof(require));
		memset(profit, 0, sizeof(profit));
		memset(cost, 0, sizeof(cost));
		cin >> n >> m;
		for(int i=0; i<n; ++i)
			cin >> profit[i];
		for(int i=0; i<m; ++i)
			cin >> cost[i];
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j) {
				cin >> require[i][j];
			}
		cout << maxProfit() << "\n";
	}
	return 0;	
}
