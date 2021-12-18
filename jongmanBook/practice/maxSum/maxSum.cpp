#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> vec;
const int MIN = numeric_limits<int>::min();

int inefficientMaxSum() {
	int n=vec.size(), ret=MIN;
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j) {
			int sum=0;
			for(int k=i; k<=j; ++k) {
				sum += vec[k];
			}
			ret = max(ret, sum);
		}
	return ret;
}

int betterSum() {
	int n=vec.size(), ret=MIN;
	for(int i=0; i<n; ++i) {
		int sum = 0;	
		for(int j=i; j<n; ++j) {
			sum += vec[j];
			ret = max(ret, sum);
		}
	}
	return ret;	
}

int partialSum() {
	int n=vec.size();
	vector<int> accumSum = vector<int>(n+1);
	accumSum[0] = 0;
	for(int i=0; i<n; ++i)
		accumSum[i+1] = vec[i] + accumSum[i];
	int ret=MIN;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<n; ++j)
			ret = max(ret, accumSum[i]-accumSum[j]);
	return ret;
}

int fastMaxSum(int lo, int hi) {
	if(lo == hi) return vec[lo];	
	int mid = (lo + hi)/2;
	int left=MIN, right=MIN, sum=0;
	for(int i=mid; i>=lo; --i) {
		sum += vec[i];
		left = max(left, sum);
	}
	sum = 0;
	for(int i=mid+1; i<=hi; ++i) {
		sum += vec[i];
		right = max(right, sum);
	}
	int single = max(fastMaxSum(lo, mid), fastMaxSum(mid+1, hi));
	return max(left+right, single);
}

int fastestMaxSum() {
	int n=vec.size(), ret=MIN;	
	int psum=0;
	for(int i=0; i<n; ++i) {
		psum = max(psum, 0) + vec[i];
		ret = max(psum, ret);
	}
	return ret;
}

int main() {
	vec.push_back(-7);	
	vec.push_back(4);	
	vec.push_back(-3);	
	vec.push_back(6);
	vec.push_back(3);	
	vec.push_back(-8);	
	vec.push_back(3);	
	vec.push_back(4);	

	cout << inefficientMaxSum() << "\n";
	cout << betterSum() << "\n";
	cout << partialSum() << "\n";
	cout << fastMaxSum(0, vec.size()-1) << "\n";
	cout << fastestMaxSum() << "\n";
}
