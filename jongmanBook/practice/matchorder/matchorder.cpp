#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//int russia[100], korea[100], participated[100];
vector<int> russia, korea;
int n;

//int maxWin(int idx) {
//	int ret = 0;
//	for(int i=0; i<n; ++i)
//		if(!participated[i]) {
//			int winPoint = (korea[i] >= russia[idx]) ? 1 : 0;
//			participated[i] = true;
//			ret = max(ret, winPoint + maxWin(idx+1));
//			participated[i] = false;
//		}
//	return ret;
//}

// greedy

int order(const vector<int>& russian, const vector<int>& korean) {
	int ret = 0;
	multiset<int> ratings(korean.begin(), korean.end());
	for(int rus=0; rus<n; ++rus) {
		if(*ratings.rbegin() < russian[rus])
			ratings.erase(ratings.begin());
		else {
			ratings.erase(ratings.lower_bound(russian[rus]));	
			++ret;
		}
	}
	return ret;
}

int greedy() {
	sort(russia.begin(), russia.end());
	sort(korea.begin(), korea.end());
	int j=0;
	int ret=0;
	for(int i=0; i<n; ++i) {
		int rus = russia[i];	
		while(j<n) {
			if(korea[j] >= rus)	{
				ret++;	
				j++;
				break;
			}
			j++;
		}
	}
	return ret;	
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		//memset(participated, 0, sizeof(participated));
		cin >> n;
		russia = korea = vector<int>(n);
		for(int i=0; i<n; ++i)
			cin >> russia[i];
		for(int i=0; i<n; ++i)
			cin >> korea[i];
		cout << order(russia, korea) << "\n";
	}
	return 0;	
}
