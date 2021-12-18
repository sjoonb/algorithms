#include <iostream>
#include <vector>
using namespace std;

vecto<int> getPartialMatchNaive(const string& N) {
	int m = N.size();
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatchNaive(N);
}

int main() {
	kmpSearch("abaabaabaabbbaabb", "aabaa");
}
