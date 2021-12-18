#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<string> wordVec[26][26];
vector<int> indegree, outdegree;

void getGraph(const vector<string>& words) {
	for(int i=0; i<26; ++i)
		for(int j=0; j<26; ++j)
			wordVec[i][j].clear();	
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	for(int i=0; i<words.size(); ++i) {
		int u = words[i][0] - 'a';	
		int v = words[i][words[i].size()-1] - 'a';
		wordVec[u][v].push_back(words[i]);
		adj[u][v]++;
		outdegree[u]++;	
		indegree[v]++;	
	}
}

void getEuiler(int here, vector<int>& path) {
	for(int there=0; there<26; ++there) {
		while(adj[here][there] > 0) {
			adj[here][there]--;
			getEuiler(there, path);
		}
	}
	path.push_back(here);
}

vector<int> getEuilerTrailOrCircuit() {
	vector<int> path;
	// trail
	for(int i=0; i<26; ++i) 
		if(outdegree[i] == indegree[i]+1) {
			getEuiler(i, path);			
			return path;
		}
	// circuit
	for(int i=0; i<26; ++i)
		if(outdegree[i]) {
			getEuiler(i, path);
			return path;
		}
	return path;
}


void solve() {
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i=0; i<n; ++i)
		cin >> words[i];
	getGraph(words);	
	vector<int> circuit = getEuilerTrailOrCircuit();
	if(circuit.size() != words.size()+1) {
		cout << "IMPOSSIBLE";
	} else {
		reverse(circuit.begin(), circuit.end());
		for(int i=0; i<circuit.size()-1; ++i) {
			if(i)
				cout << " ";
			int u = circuit[i];
			int v = circuit[i+1];
			cout << wordVec[u][v].back();
			wordVec[u][v].pop_back();
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}

}
