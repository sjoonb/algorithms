#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(10);

int solve() {
	sort(vec.begin(), vec.end());
	return vec[7];
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		for(int i=0; i<10; ++i)
			cin >> vec[i];
		cout << solve() << "\n";	
	}
}
