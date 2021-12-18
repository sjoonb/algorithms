#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<int> finished;
vector<int> sccId;
stack<int> s;

int cnt;
int sccCnt;

void makeGraph() {
	int n, e;
	cin >> n >> e;	
	adj = vector<vector<int> >(n, vector<int>(n, 0));
	discovered = sccId = vector<int>(n, -1);
	finished = vector<int>(n, 0);
	for(int i=0; i<e; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;	
	}
}

int tarjan(int here) {
	discovered[here] = cnt++;
	s.push(here);
	int parent = discovered[here];
	for(int there=0; there<adj[here].size(); ++there) {
		if(adj[here][there]) {
			if(discovered[there] == -1) {
				parent = min(parent, tarjan(there));	
			} else if(!finished[there]) {
				parent = min(parent, discovered[there]);	
				// TODO::if not test
			}
		}
	}
	if(parent == discovered[here]) {
		while(true) {
			int top = s.top();
			sccId[top]= sccCnt;
			finished[top] = 1;
			s.pop();			
            if(top == here)
                break;
		}
		sccCnt++;
	}
	return parent;
}

int main() {
	makeGraph();
	for(int i=1; i<sccId.size(); ++i) {
		if(!finished[i])	
			tarjan(i);
	}
	cout << "{";
	for(int i=1; i<sccId.size(); ++i) {
		if(i!=1)
			cout << ", ";
		cout << "[" << i << "]: " << sccId[i];
	}
	cout << "}";
}
