#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

vector<int> selectionSort(vector<int> arr) {
	int n = arr.size();
	for(int i=0; i<n; ++i) {
		int minIdx = i;
		for(int j=i+1; j<n; ++j) {
			if(arr[minIdx] > arr[j])
				minIdx = j;
		}
		swap(arr[i], arr[minIdx]);
	}
	return arr;
}

vector<int> insertionSort(vector<int> arr) {
	int n = arr.size();
	for(int i=0; i<n; ++i) {
		int j=i;
		while(j>0 && arr[j-1] > arr[j]) {
			swap(arr[j-1], arr[j]);
			j--;
		}
	}
	return arr;
}

void merge(vector<int>& arr, int l, int m, int r) {
	int i, j, k;	
	vector<int> c = vector<int>(arr.size());
	i = l, k = l, j = m+1;	
	while(i<=m && j<=r) {
		if(arr[i] < arr[j])
			c[k] = arr[i++];
		else
			c[k] = arr[j++];
		k++;
	}
	while(i<=m)
		c[k++] = arr[i++];
	while(j<=r)
		c[k++] = arr[j++];
	for(i=l; i<=r; ++i)
		arr[i] = c[i];	
}


void mergeSort(vector<int>& arr, int l, int r) {
	if(l >= r)
		return;
	int m = (l+r)/2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
}

int partition(vector<int>& arr, int l, int r) {
	int pivot = arr[r];	
	int i = l-1;
	for(int j=l; j<r; ++j) {
		if(arr[j] <= pivot) {
			i++;	
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return (i+1);
}

void quickSort(vector<int>& arr, int l, int r) {
	if(l >= r)
		return;	
	int p = partition(arr, l, r);
	quickSort(arr, l, p-1);
	quickSort(arr, p+1, r);
}

void print(const vector<int>& arr) {
	for(int i=0; i<arr.size(); ++i) 
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	vec = vector<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	vector<int> selectionVec = selectionSort(vec);
	print(selectionVec);	

	vector<int> insertionVec = insertionSort(vec);
	print(insertionVec);

	vector<int> mergeVec = vec;
	mergeSort(mergeVec, 0, mergeVec.size()-1);
	print(mergeVec);

	vector<int> quickVec = vec;
	quickSort(quickVec, 0, quickVec.size()-1);
	print(quickVec);

}

