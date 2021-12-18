#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int order[4] = {3, 4, 1, 2};
string str;
int idx;

string quad() {
	if(str[idx] != 'x')
		return string(1, str[idx]);
	idx++;
	vector<string> ret;
	ret.resize(4);
	for(int i=0; i<4; ++i) {
		ret[i] = quad();
		idx++;
	}
	idx--;
	string result = "x" + ret[2] + ret[3] + ret[0] + ret[1];
	return result;	
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		idx = 0;
		cin >> str;
		cout << quad() << "\n";
	}
	return 0;	
}
