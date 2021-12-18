#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void dfs(int here) {
	visited[here] = true;	
	for(int i=0; i<adj[here].size(); ++i) {
		if(adj[here][i] && !visited[i]) {
			dfs(i);
		}
	}
	order.push_back(here);
}

void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));	
	for(int j=1; j<words.size(); ++j) {
		int i=j-1, len = min(words[i].size(), words[j].size());
		for(int k=0; k<len; ++k) {
			if(words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

void solve() {
	vector<string> words;
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		string word;
		cin >> word;
		words.push_back(word);
	}
	makeGraph(words);	
//	for(int i=0; i<26; ++i)
//		for(int j=0; j<26; ++j) {
//			if(adj[i][j])
//				cout << (char)(i + 'a')  << " " << (char)(j + 'a') <<  "\n";
//		}
	visited = vector<bool>(26, false);
	order.clear();
	for(int i=0; i<26; ++i)
		if(!visited[i])
			dfs(i);
	reverse(order.begin(), order.end());
	for(int i=0; i<26; ++i)
		for(int j=i+1; j<26; ++j)
			if(adj[order[j]][order[i]]) {
				cout << "INVALID HYPOTHESIS";	
				return;
			}

//	reverse(order.begin(), order.end());
	for(int i: order)
		cout << (char)(i + 'a');
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();	
		cout << "\n";
	}
}
