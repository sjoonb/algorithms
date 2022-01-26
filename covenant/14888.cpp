#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> operand(11);
vector<int> _operator(4); // + - * /

int n;
int _min = 1e9 + 1;
int _max = -1e9 - 1;

int calc(int a, int b, int op) {
	int ret;
	switch(op) {
		case 0:
			ret = a+b;
			break;
		case 1:
			ret = a-b;
			break;
		case 2:
			ret = a*b;
			break;
		case 3:
			ret = a/b;
			break;
	}
	return ret;
}

void solve(int depth, int sum) {
	if(depth == n-1) {
		if(sum < _min) _min = sum;
		if(sum > _max) _max = sum;	
		return;
	}
	for(int op=0; op<4; ++op) {
		if(_operator[op]) {
			_operator[op]--;	
			int res = calc(sum, operand[depth+1], op);
			solve(depth+1, res);
			_operator[op]++;	
		}
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) 
		cin >> operand[i];
	for(int i=0; i<4; ++i)
		cin >> _operator[i];
	solve(0, operand[0]);
	cout << _max << endl;
	cout << _min << endl;
}
