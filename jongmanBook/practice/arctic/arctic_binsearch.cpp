#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
double dist[100][100];

bool decision(double d) {
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for(int there=0; there<n; ++there) 
			if(!visited[there] && dist[here][there] <= d) {
				visited[there]=true;
				q.push(there);
			}
	}
	return seen == n;
}

double optimize() {
	double lo = 0, hi = sqrt(2*1000*1000)+1;
	for(int it=0; it<100; ++it) {
		double mid = (lo + hi)/2;
		if(decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;	
}

void read() {
	cin >> n;
	vector<pair<double, double> > coordinates;
	for(int i=0; i<n; ++i) {
		double y, x;
		cin >> y >> x;
		coordinates.emplace_back(y, x);
	}
	for(int i=0; i<coordinates.size(); ++i) {
		double cy = coordinates[i].first;
		double cx = coordinates[i].second;
		for(int j=i+1; j<coordinates.size(); ++j) {
			double ny = coordinates[j].first;
			double nx = coordinates[j].second;
			double distance = sqrt(pow(ny-cy, 2) + pow(nx-cx, 2));
			distance = round(distance*100)/100;
			dist[i][j] = distance;
			dist[j][i] = distance;
		}
	}
}

int main() {
	cout.precision(2);
	int cases;
	cin >> cases;
	for(int cc=0; cc<cases; ++cc) {
		read();
		cout << fixed;
		cout << optimize() << "\n";
	}
}
