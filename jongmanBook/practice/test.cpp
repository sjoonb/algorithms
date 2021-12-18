#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
using namespace std;

bool visited[5];
vector<string> ret;

int permutation(string str, int r, string path = "") {
	if(path.size() == r) {
		ret.push_back(path);
		return 1;
	}
	int cnt = 0;
	for(int there=0; there<str.size(); ++there) {
		if(!visited[there]) {
			visited[there] = true;
			path.push_back(str[there]);		
			cnt += permutation(str, r, path);
			visited[there] = false;
			path.pop_back();
		}
	}
	return cnt;
}

//int combination(string str, int r, int here=-1, string path = "") {
//	if(path.size() == r) {
//		ret.push_back(path);
//		return 1;
//	}
//	int cnt=0;
//	for(int there=here+1; there<str.size(); ++there) {
//			path.push_back(str[there]);		
//			cnt += combination(str, r, there, path);
//			path.pop_back();
//		}
//	return cnt;
//}


int combination(string str, int r, int here=0, string path = "") {
	if(path.size() == r) {
		ret.push_back(path);
		return 1;
	} else if(here == str.size()) {
		return 0;
	}
	int cnt = 0;
	path.push_back(str[here]);
	cnt += combination(str, r, here+1, path);
	path.pop_back();
	cnt += combination(str, r, here+1, path);
	return cnt;
}

int main() {
	string str = "ABCDE";
//	cout << permutation(str, 3) << "\n";
//	for(int i=0; i<ret.size(); ++i)
//		cout << ret[i] << "\n";
	ret.clear();
	memset(visited, false, sizeof(visited));
	cout << combination(str, 3) << "\n";
	for(int i=0; i<ret.size(); ++i)
		cout << ret[i] << "\n";
}



