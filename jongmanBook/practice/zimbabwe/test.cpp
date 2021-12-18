#include <iostream>
using namespace std;

int main() {
	string s = "abc";
	string k = s;	
	s[0] = 'd';
	cout << k;
	cout << s;
}
