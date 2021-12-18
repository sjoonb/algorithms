#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> arr;
const int INF = 1e9;

int stupid() {
	int maxSum = 0;
	for(int i=1; i<=10000; ++i) {
		int sum=0;
		for(int j=0; j<arr.size(); ++j) {
			if(arr[j] >= i)	{
				sum += i;
				maxSum = max(maxSum, sum);
			}
			else {
				sum = 0;
			}
		}
		
	}
	return maxSum;
}

int solveStack() {
	stack<int> remaining;
	arr.push_back(0);	

	int ret=0;
	for(int i=0; i<arr.size(); ++i) {
		while(!remaining.empty() && arr[remaining.top()] >= arr[i]) {
			int j = remaining.top();
			remaining.pop();	
			int width;
			if(remaining.empty()) {
				width = i;
			} else {
				width = (i-remaining.top()-1);
			}
			ret = max(ret, arr[j] * width);
		}
		remaining.push(i);
	}
	return ret;
}

int fence(int l, int r) {
	if(l>=r) return arr[l];
	int m = (l+r)/2;
	int a = m-1;
	int b = m+1;
	int minHeight=arr[m];
	int maxArea = minHeight;
	while(a>=l || b<=r) {
		int height;
		if(b>r) {
			height = arr[a--];
		} else if(a<l) {
			height = arr[b++];
		} else {
			height = (arr[a] >= arr[b]) ? arr[a--] : arr[b++];
		}
		minHeight = min(minHeight, height);
		int area = (b-a-1) * minHeight;
		maxArea = max(maxArea, area);
	}
	int single = max(fence(l, m), fence(m+1, r));
	return max(maxArea, single);
}

int main() {
	int cases;
	cin >> cases;
	for(int c=0; c<cases; ++c) {
		int n;
		cin >> n;
		arr.resize(n);
		for(int i=0; i<n; ++i) cin >> arr[i];
		cout << solveStack() << "\n";
	}
	return 0;	
}
