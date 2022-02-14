#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define INF (1<<30)


int N;
vector<pair<int, int> > points;
set<pair<int, int> > bst;

int dist(const pair<int, int> &a, const pair<int, int> &b) {
	return pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
}

int solve() {
	int minDist = dist(points[1], points[0]);
	bst.emplace(points[0].x, points[0].y);
	bst.emplace(points[1].x, points[1].y);
	int j=0;
	for(int i=2; i<N; ++i) {
		while(j < i && pow(points[i].x - points[j].x, 2) >= minDist) {
			bst.erase({points[j].x, points[j].y});
			j += 1;
		}
		auto begin = bst.lower_bound(make_pair(-INF, points[i].y - sqrt(minDist)));
		auto end = bst.upper_bound(make_pair(INF, points[i].y + sqrt(minDist)));
		for(auto it = begin; it != end; it++)
			minDist = min(minDist, dist(points[i], {it->first, it->second}));
		bst.emplace(points[i].x, points[i].y);
	}
	return minDist;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for(int i=0; i<N; ++i) {
		int x, y;
		cin >> x >> y;
		points.emplace_back(x, y);
	}
	sort(points.begin(), points.end());
	cout << solve();
	return 0;
}

