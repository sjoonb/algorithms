#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > adj;
vector<int> discvoered, sscId;
stack<int> st;
int sccCnt, vertexCnt;

bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second <= b.first || b.second <= a.first;	
}

int scc(int here) {
	int ret = discovered[here] = vertexCounter++;	
	st.push(here);
	for(int i=0; i<adj[here].size(); ++i) {
		int there=adj[here][i];	
		if(discovered[there] == -1) {
			ret = min(ret, scc(there));	
		} else if(sscId[there] == -1) {
			ret = min(ret, discovered[there]);
		}
	}
	if(ret == discovered[here]) {
		while(true) {
			int t = st.top();	
			st.pop();
			sscId[t] = sccCnt;
			if(t==here) break;
		}
		sccCnt++;
	}
	return ret;
}

vector<int> tarjanSCC() {
	discovered = sscId = vector<int>(adj.size(), -1);
	sscCnt = vertexCnt = 0;
	for(int i=0; i<adj.size(); ++i)
		if(discovered[i] == -1)
			scc(i);
	return sccId;
}

vector<int> solve2SAT() {
	int n = adj.size();
	vector<int> label = tarjanSCC();
	for(int i=0; i<n; i+=2)
		if(label[i]==label[i+1])
			return vector<int>();

	vector<int> value(n, -1);
}

void makeGraph(const vector<pair<int, int> >& meetings) {
	int vars = meetings.size();	
	adj.clear(); adj.resize(vars*2);
	for(int i=0; i<vars; i+=2) {
		int j = i+1;	
		adj[i*2+1].push_back(j*2);
		adj[j*2+1].push_back(i*2);
		adj[i*2].push_back(j*2+1);
		adj[j*2].push_back(i*2+1);
	}
	for(int i=0; i<vars; ++i)
		for(int j=0; j<i; ++j) {
			if(!disjoint(meetings[i], meetings[j])) {
				adj[i*2].push_back(j*2+1);				
				adj[j*2].push_back(j*2+1);				
			}
		}
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int> > meetings(2*n);
	for(int i=0; i<n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		meetings[2*i] = make_pair(a, b);
		meetings[2*i + 1] = make_pair(c, d);
	}
	makeGraph(meetings);
	vector<int> ret = solve2SAT();
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}
