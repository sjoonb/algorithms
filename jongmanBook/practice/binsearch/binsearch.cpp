#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int binsearch(int x) {
	int l = 0, r = vec.size()-1;
	while(l <= r) {
		int m = (l+r)/2;
		if(vec[m] == x) return m;
		else if(vec[m] < x)
			l = m+1;
		else
			r = m-1;
	}
	return -1;
}

int binsearchRec(int x, int l, int r) {
	if(l<=r) {
		int m = (l+r)/2;	
		if(x == vec[m]) return m;
		else if(x > vec[m]) return binsearchRec(x, m+1, r);
		else return binsearchRec(x, l, m-1);
	}
	return -1;
}

int main() {
	vec = vector<int>{ 1, 3, 5, 7, 9, 11, 13 };
	for(int i=0; i<14; ++i)
		cout << i << ": " << binsearchRec(i, 0, vec.size()-1) << "\n";
}
