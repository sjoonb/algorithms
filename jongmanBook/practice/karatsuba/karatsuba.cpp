#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);
	int size = num.size();
	for(int i=0; i<size-1; ++i) {
		if(num[i] < 0) {
			int borrow = (abs(num[i]) + 9)/10;	
			num[i+1] -= borrow;
			num[i] += 10*borrow;
		} else {
			num[i+1] += num[i]/10;	
			num[i] %= 10;
		}
	}
	while(num.size() > 1 && num.back() == 0)
		num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size(), 0);
	int aSize = a.size();
	int bSize = b.size();
	for(int i=0; i<aSize; ++i)
		for(int j=0; j<bSize; ++j)
			c[i+j] += a[i]*b[j];
	normalize(c);
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
	int newSize = a.size() < b.size() + k ? b.size() + k : a.size();
	while(a.size() != newSize) a.push_back(0);
	for(int i=0; i<b.size(); ++i)
		a[i+k] += b[i];
	normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
	for(int i=0; i<b.size(); ++i) {
		a[i] -= b[i];	
	}
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if(an < bn)
		return karatsuba(b, a);
	if(an==0 || bn==0)
		return vector<int>();
	if(an <= 5)
		return multiply(a, b);

	int half = an/2;

	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(half, bn));
	vector<int> b1(b.begin() + min<int>(half, bn), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half*2);
	return ret;
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

	cout << "multiply: ";
	result = multiply(a, b);
	for(int i=result.size()-1; i>=0; --i) 
		cout << result[i];
	cout << endl;

	cout << "kartsuba: ";
	result = karatsuba(a, b);
	for(int i=result.size()-1; i>=0; --i) 
		cout << result[i];
	cout << endl;
}
