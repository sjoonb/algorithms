#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long

map<string, int> clothes;
int N;

int main() {
	int cases;
	cin >> cases;	
	for(int cc=0; cc<cases; ++cc) {
		clothes.clear();
		cin >> N;
		for(int i=0; i<N; ++i) {
			string name, type;
			cin >> name >> type;
			auto it = clothes.find(type);
			if(it != clothes.end()) {
				it->second++;
			} else {
				clothes.insert({type, 1});
			}
		}
		int ret = 1;
		for(auto it=clothes.begin(); it != clothes.end(); it++) {
			ret *= (it->second + 1);
		}
		ret--;
		cout << ret << "\n";
	}
	return 0;
}


