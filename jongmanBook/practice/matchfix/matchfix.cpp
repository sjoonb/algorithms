#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m;
int xmatch;
int wins[12];
int capacity[114][114], flow[114][114];
int match[100][2];

void print() {
	int V = n + m + 2;
	for(int i=0; i<V; ++i) {
		for(int j=0; j<V; ++j) {
			if(capacity[i][j])
				cout << i << " -> " << j << " [" << capacity[i][j] << "]\n";	
		}
	}
}

int fordFulkerson(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	int V = n + m + 2;
	while(true) {
		vector<int> parent(V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1) {
			int here = q.front(); q.pop();	
			for(int there=0; there<V; ++there)
				if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}
		if(parent[sink] == -1) break;
		int amt=987654321;
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

bool canWin(int w) {
	for(int i=0; i<n; ++i) {
		capacity[i+m+2][1] = ((i==0 ? w: w-1) - wins[i]);
		if(capacity[i+m+2][1] < 0) return false;
	}
	return (fordFulkerson(0, 1) == m);
}

int solution() {
	int ret = -1;
	memset(capacity, 0, sizeof(capacity));
	for(int i=0; i<m; ++i) {
		capacity[0][i+2] = 1;	
		for(int j=0; j<2; ++j)
			capacity[i+2][m+2+match[i][j]] = 1;
	}
	for(int i=wins[0]; i<= wins[0] + xmatch; ++i) {
		if(canWin(i))
			return i;
	}
	return ret;
}

void solve() {
	cin >> n >> m;
	memset(wins, 0, sizeof(wins));
	memset(match, 0, sizeof(match));
	xmatch = 0;
	for(int i=0; i<n; ++i) cin >> wins[i];
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		match[i][0] = a;
		match[i][1] = b;
		if(a==0 | b==0)
			xmatch++;
	}
	cout << solution() << "\n";
}


int main() {
	int t;
	cin >> t;
	while(t--)
		solve();	
	return 0;	
}
