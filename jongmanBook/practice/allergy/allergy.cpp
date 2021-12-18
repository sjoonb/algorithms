#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m, best;
vector<int> eaters[50], canEat[50];

//void search(int food, vector<int>& edible, int chosen) {
//	if(chosen >= best)
//		return;
//	if(food == m) {	
//		if(find(edible.begin(), edible.end(), 0) == edible.end())
//			best = chosen;
//		return;
//	}
//	search(food+1, edible, chosen);
//	for(int i=0; i<eaters[food].size(); ++i)
//		edible[eaters[food][i]]++;
//	search(food+1, edible, chosen+1);
//	for(int i=0; i<eaters[food].size(); ++i)
//		edible[eaters[food][i]]--;
//}

void search(vector<int>& edible, int chosen) {
	if(chosen >= best)
		return; 
	int first=0;
	while(first < n && edible[first]>0) first++;
	if(first == n) { best = chosen;  return; }
	for(int i=0; i<canEat[first].size(); ++i) {
		int food = canEat[first][i];
		for(int j=0; j<eaters[food].size(); ++j)
			edible[eaters[food][j]]++;
		search(edible, chosen+1);
		for(int j=0; j<eaters[food].size(); ++j)
			edible[eaters[food][j]]--;
	}
}

int main() {
	int cases;
	cin >> cases;
	for(int cs=0; cs<cases; ++cs) {
		cin >> n >> m;	
		best = m;
		map<string, int> index;
		for(int i=0; i<n; ++i) {
			string name;
			cin >> name;
			index[name] = i;
		}
		for(int i=0; i<m; ++i)
			eaters[i].clear();
		for(int i=0; i<n; ++i)
			canEat[i].clear();
		for(int i=0; i<m; ++i) {
			int num;
			cin >> num;
			for(int j=0; j<num; ++j) {
				string name;
				cin >> name;	
				eaters[i].push_back(index[name]);
				canEat[index[name]].push_back(i);
			}
		}
		vector<int> edible(n);
		search(edible, 0);
		cout << best << "\n";
	}
}
