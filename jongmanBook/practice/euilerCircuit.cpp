#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;

void getEuilerCircuit(int here, vector<int>& circuit) {
	for(int there=0; there < adj[here].size(); ++there) {
		while(adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEuilerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}

int main() {
	
	return 0;
}

