#include <iostream>
#include <vector>
using namespace std;

vector<int> R[12], C[10];
int n, k, m, l;


void solve(int semester) {
	if(semester == M)
		return 0;
	for(int i=0; i<C[semester].size(); ++i) {
		int subject = C[semester][i];
		if(!seleceted[subject] && canTake(subject)) {
			
		}
	}
}

void read() {
	cin >> n >> k >> m >> l;
	for(int i=0; i<n; ++i) {
		prerequisite[i] = 0;
		int r;
		cin >> r;
		for(int j=0; j<r; ++j) {
			int required;
			cin >> required;
			prerequisite[i] |= (1 << required);
		}
	}
	for(int i=0; i<m; ++i) {
		prerequisite[i] = 0;
		int r;
		cin >> r;
		for(int j=0; j<r; ++j) {
			int required;
			cin >> required;
			prerequisite[i] |= (1 << required);
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		read();
	}
}
