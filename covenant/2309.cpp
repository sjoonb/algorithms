#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec(9); 
vector<bool> member(9, false);

void solve(int src, int sum, int k) {
	if(k == 7) {
		if(sum == 100) {
			vector<int> sol;
			for(int i=0; i<9; ++i) {
				if(member[i])
					sol.push_back(vec[i]);
			}
			sort(sol.begin(), sol.end());
			for(int i=0; i<7; ++i)
				printf("%d\n", sol[i]);
			exit(0);
		}
		else
			return;
	}
	for(int i=src+1; i<9; ++i) {
		member[i] = true;
		solve(i, sum + vec[i], k+1);	
		member[i] = false;
	}
}

void simple() {
	int sum = 0;
	for(int i=0; i<9; ++i)
		sum += vec[i];

	for(int i=0; i<9; ++i) {
		sum -= vec[i];
		for(int j=i+1; j<9; ++j)  {
			sum -= vec[j];	
			if(sum == 100) {
				vec[i] = -1;
				vec[j] = -1;
				sort(vec.begin(), vec.end());
				for(int k=2; k<vec.size(); ++k)
					cout << vec[k] << endl;
				return;
			}
			sum += vec[j];
		}
		sum += vec[i];
	}

}

int main() {
	for(int i=0; i<9; ++i)
		cin >> vec[i];
	simple();
//	solve(-1, 0, 0);
}
