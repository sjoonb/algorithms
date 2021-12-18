#include <iostream>
#include <stdlib.h>
using namespace std;

bool isMultiple3In(int num) {
	string s = to_string(num);
	for(int i=0; i<s.size(); ++i) {
		if(s[i]!='0' && (s[i]-'0')%3==0)
			return true;
	}
	return false;
}

int main() {
	for(int i=1; i<200; ++i) {
		if(isMultiple3In(i))
			cout << '*';
		else
			cout << i;
	}
}
