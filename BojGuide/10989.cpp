#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 1e7;

int N;
int seq[SIZE];

int main() {
	cin >> N;	
	for(int i=0; i<N; ++i)
		cin >> seq[i];
	sort(seq, seq+N);
	for(int i=0; i<N; ++i)
		cout << seq[i] << "\n";
	return 0;
}
