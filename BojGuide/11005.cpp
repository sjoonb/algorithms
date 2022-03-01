#include <iostream>
#include <algorithm>
using namespace std;

int N, B;

string convert(int N, int B) {
	if(N == 0)
		return "0";
	string ret = "";
	while(N != 0) {
		ret += N%B + ((N%B < 10) ? '0' : 'A' - 10);
		N /= B;	
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	cin >> N >> B;	
	cout << convert(N, B);
	return 0;
}
