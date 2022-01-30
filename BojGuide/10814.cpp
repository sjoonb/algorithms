#include <iostream>
#include <algorithm>
using namespace std;

int N;
tuple<int, string, int> members[100000];

bool cmp(const tuple<int, string, int> &a, const tuple<int, string, int> &b) {
	if(get<0>(a) == get<0>(b))
		return get<2>(a) < get<2>(b);
	return get<0>(a) < get<0>(b);
}

int main() {
	int cnt = 0;
	cin >> N;
	for(int i=0; i<N; ++i) {
		int age;
		string name;	
		cin >> age >> name;
		members[i] = make_tuple(age, name, cnt++);
	}
	sort(members, members+N, cmp);
	for(int i=0; i<N; ++i)
		cout << get<0>(members[i]) << " " << get<1>(members[i]) << "\n";
	return 0;
}
