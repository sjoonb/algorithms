#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	s.push(1);
	s.push(2);
	s.push(3);
	while(!s.empty() && s.top() != 4) {
		cout << s.top();
		s.pop();
	}
}
