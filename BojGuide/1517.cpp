#include <iostream>
#include <vector>
using namespace std;

int N;
long long ret;
vector<int> seq;

void merge(int l, int r, int m) {
	int i = l;
	int j = m+1;
	int k = 0;
	int size = r - l + 1;
	vector<int> merged(size);
	long long cnt;
	cnt = 0;
	while(i <= m && j <= r) {
		if(seq[i] <= seq[j])	 {
			merged[k] = seq[i++];
			ret += cnt;
		} else {
			merged[k] = seq[j++];
			cnt++;
		}
		k++;
	}
	while(i <= m) {
		merged[k++] = seq[i++];
		ret += cnt;
	}
	while(j <= r)
		merged[k++] = seq[j++];
	for(int idx=0; idx<size; ++idx)
		seq[l+idx] = merged[idx];
}

void mergeSort(int l, int r) {
	if(l >= r)
		return;
	int m = (l + r) / 2;
	mergeSort(l, m);
	mergeSort(m+1, r);
	merge(l, r, m);
}

int main() {
	cin >> N;
	seq = vector<int>(N);
	for(int i=0; i<N; ++i)
		cin >> seq[i];
	mergeSort(0, N-1);
	cout << ret;
	return 0;
}
