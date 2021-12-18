#include <iostream>
#include <stack>
using namespace std;

bool isOpenBracket(int bracket) {
	return bracket == '(' || bracket == '[' || bracket == '{';	
}

int bracketType(int bracket) {
	if(bracket == '(' || bracket == ')') {
		return 0;
	} else if(bracket == '[' || bracket == ']') {
		return 1;
	} else {
		return 2;
	}
}

bool wellMatched(string& brackets) {
	stack<int> s;
	for(int i=0; i<brackets.size(); ++i) {
		int bracket = brackets[i];	
		if(isOpenBracket(bracket)) {
			s.push(bracket);
		} else {
			if(!s.empty() && bracketType(s.top()) == bracketType(bracket)) {
				s.pop();
			} else {
				return false;
			}
		}
	}
	return s.empty();
}

int main() {
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		string brackets;
		cin >> brackets; 
		wellMatched(brackets) ? cout << "YES" : cout << "NO";
		cout << "\n";
	}
	return 0;
}
