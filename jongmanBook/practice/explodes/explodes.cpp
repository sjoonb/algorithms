#include <iostream>
#include <algorithm>
using namespace std;

int n, explodes[100];
const char ch[4] = {'A', 'B', 'C', 'D'};

bool isStable(int set) {
	for(int i=0; i<n; ++i) {
		if((set & (1 << i)) && (set & explodes[i]))
			return false;
	}
	return true;
}

void myReverse(int* ret, int n) {
	int lo=0, hi=n-1;
	while(lo < hi) {
		swap(ret[lo++], ret[hi--]);
	}
}

void printBinary(int set) {
	int ret[4] = { 0,};
	int	idx=0;	
	while(set/2 != 0) {
		ret[idx] = set%2;
		set /= 2;
		idx++;
	}
	ret[idx] = set;
	myReverse(ret, n);
	for(int i=0; i<n; ++i)
		if(ret[i])
			cout << ch[i] << " ";
	cout << "\n";
}

int countStableSet() {
	 int ret = 0;
	 for(int set=1; set<(1<<n); ++set) {
		 if(!isStable(set))
			 continue;
		 bool canAdd = false;
		 for(int i=0; i<n; ++i) {
			 if((set & (1 << i)) == 0 && (set & explodes[i]) == 0) {
				 canAdd = true;
				 break;
			 }
		 }
		 if(!canAdd) {
			 printBinary(set);
			 ret++;
		 }
	 }
 return ret;
}

int main() {
	// {0, 1}, {2, 3} explodes pair
	explodes[0] = (1 << 1);
	explodes[1] = (1 << 0);
	explodes[2] = (1 << 3);
	explodes[3] = (1 << 2);

	n = 4;
	cout << countStableSet();
}
