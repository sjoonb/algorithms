#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int bracketValue(char ch) {
    switch(ch) {
        case '(':
            return 0;
        case ')':
            return 2;
        case '[':
            return 1;
        case ']':
            return 3;
        default:
            return -1;
    }
}

int solve(const string& str) {
    stack<char> s;

    int sum = 0;
    int temp = 1;
    for(int i=0; i<str.size(); ++i) {
        char ch = str[i];
        if(ch == '(' || ch == '[') {
            s.push(ch);
            temp *= (bracketValue(ch) % 2 + 2);
        }
        else {
            if(s.empty() || bracketValue(ch)%2 != bracketValue(s.top())%2)
                return 0;

            if(bracketValue(str[i-1]) + 2 == bracketValue(str[i]))
                sum += temp;

            int value = bracketValue(ch) %2 + 2;
            temp /= value;
            s.pop();
        }
    }
    if(s.empty())
        return sum;
    else
        return 0;
}


int main() {
	string str;
	cin >> str;
    cout << solve(str);
    
    return 0;
}
