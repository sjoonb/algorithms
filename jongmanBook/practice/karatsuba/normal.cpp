#include <iostream>
#include <vector>
using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);
	for(int i=0; i+1 < num.size(); ++i) {
		if(num[i] < 0) {
   		    int borrow = (abs(num[i]) + 9) / 10;
 		    num[i + 1] -= borrow;
 		    num[i] += borrow * 10;
		} else {
			num[i+1] += num[i]/10;
			num[i] %= 10;
		}
	}
	while(num.size()>1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size(), 0);	
	for(int i=0; i<a.size(); ++i)
		for(int j=0; j<b.size(); ++j)
			c[i+j] += a[i] * b[j];
	normalize(c);
	return c;
}

int main() {
	vector<int> a, b, result;
	string number;

	cout << "first num: ";
	cin >> number;
	for(int i=number.size()-1; i>=0; --i)
		a.push_back(number[i] - '0');

	cout << "second num: ";
	cin >> number;
	for(int i=number.size()-1; i>=0; --i)
		b.push_back(number[i] - '0');

	vector<int> vec = multiply(a, b);
	reverse(vec.begin(), vec.end());
	for(int i=0; i<vec.size(); ++i)
		cout << vec[i];
	return 0;	
}
