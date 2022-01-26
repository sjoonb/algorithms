#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec(1001);

void precalc() {
	int cnt = 1;
	int i = 1;
	while(cnt <= 1000) {
		for(int j=0; j<i; ++j) {
			if(cnt > 1000)
				return;
			vec[cnt++] = i;	
		}
		++i;
	}
}

int main() {
	precalc();
	int a, b;
	cin >> a >> b;
	int sum=0;
	for(int i=a; i<=b; ++i)
		sum += vec[i];
	cout << sum;
}
